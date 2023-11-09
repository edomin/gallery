#include "dirscroller.h"

DirScroller::DirScroller() {}

void DirScroller::open(const QString& filename) {
    if (filename == "")
        return;

    m_dir.cd(QFileInfo{filename}.absoluteDir().absolutePath());
    m_content = m_dir.entryList({"*.jpg", "*.png"}, QDir::Files, QDir::Name);

    for (auto it = m_content.cbegin(); it != m_content.cend(); ++it) {
        if (QFileInfo{filename}.fileName() == *it) {
            m_cur_entry = it;

            break;
        }
    }

    Q_ASSERT(m_cur_entry != m_content.cend());
}

void DirScroller::prev() {
    if (m_cur_entry == m_content.cend())
        return;

    if (m_cur_entry == m_content.cbegin())
        m_cur_entry = m_content.cend();

    m_cur_entry--;
}

void DirScroller::next() {
    if (m_cur_entry == m_content.cend())
        return;

    if (++m_cur_entry == m_content.cend())
        m_cur_entry = m_content.cbegin();
}

QString DirScroller::get_filename() const {
    return (m_cur_entry != m_content.cend())
        ? m_dir.absoluteFilePath(*m_cur_entry)
        : "";
}
