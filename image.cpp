#include "image.h"

namespace {

constexpr int PERCENTS_MIN_LIGHTER = -99;
constexpr int PERCENTS_MIN = -100;
constexpr int PERCENTS_MAX = 100;
constexpr int PERCENTS_TO_LIGHTER_OFFSET = 100;

}

Image::Image() {}

void Image::load(const QString& filename) {
    if (filename.isEmpty()) {
        m_source = {};
        m_brightened = {};

        return;
    }
    Q_ASSERT(m_source.load(filename));
    m_brightened = m_source.convertToFormat(QImage::Format_RGBA8888,
     Qt::ColorOnly);
}

void Image::set_brightness(int percents) {
    Q_ASSERT(PERCENTS_MIN <= percents <= PERCENTS_MAX);

    if (m_source.isNull())
        return;

    for (int y = 0; y < m_source.height(); y++) {
        for (int x= 0; x < m_source.width(); x++) {
            QColor color = m_source.pixelColor(x, y);

            m_brightened.setPixelColor(x, y,
                color.lighter(
                 qBound(PERCENTS_MIN_LIGHTER, percents, PERCENTS_MAX)
                 + PERCENTS_TO_LIGHTER_OFFSET
                )
            );
        }
    }
}

QPixmap Image::get_pixmap() const {
    return m_brightened.isNull() ? QPixmap{} : QPixmap::fromImage(m_brightened);
}
