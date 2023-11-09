#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QPixmap>
#include <QString>

class Image
{
public:
    Image();
    void load(const QString& filename);
    void set_brightness(int percents);
    QPixmap get_pixmap() const;

private:
    QImage m_source{};
    QImage m_brightened{};
};

#endif // IMAGE_H
