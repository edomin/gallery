#ifndef DIRSCROLLER_H
#define DIRSCROLLER_H

#include <QDir>

class DirScroller
{
public:
    DirScroller();

    void open( const QString& filename);
    void prev();
    void next();
    QString get_filename() const;

private:
    QStringList                 m_content{};
    QDir                        m_dir{};
    QStringList::const_iterator m_cur_entry = m_content.cend();
};

#endif // DIRSCROLLER_H
