ios_calc
========

我的第一个ios程序-简单计算器

void Dialog::handle()
{
    QString srcPath("C:\\Users\\Administrator\\Desktop\\aaa.png");
    QString logoPath("C:\\Users\\Administrator\\Desktop\\logo.png");
    QString link("http://www.baidu.com/");
    QString linkText("www.baidu.com");

    setLogoToClipboard(QPixmap(srcPath), QPixmap(logoPath), link, linkText);
}


void Dialog::setLogoToClipboard(QPixmap pixmap, const QPixmap &logo, const QString &linkAddress, const QString &linkText)
{
    QString tempPath = QDir::tempPath();
    const QString tempImageName = "temp_sumscope_quote_logo_to_clipboard.png";
    QDir tempDir(tempPath);
    tempDir.remove(tempImageName);
    tempPath += QDir::separator() + tempImageName;
    qDebug() << tempPath;

    QPainter painter(&pixmap);
    painter.drawPixmap(pixmap.width() - logo.width(), 0, logo.width(), logo.height(), logo);
    pixmap.save(tempPath);

    QString html = QString("<html><body><img src=\"file:///%1\" width=\"%2\" height=\"%3\"/><br><a href=\"%4\">%5</a></body></html>")
            .arg(tempPath).arg(pixmap.width()).arg(pixmap.height()).arg(linkAddress).arg(linkText);
    QMimeData *mimeData = new QMimeData();
    mimeData->setData("text/html", html.toLocal8Bit());
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setMimeData(mimeData);
}
