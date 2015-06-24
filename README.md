ios_calc
========

我的第一个ios程序-简单计算器

    QString srcPath("C:\\Users\\tujiawei\\Desktop\\xxx.png");
    QString logoPath("C:\\Users\\tujiawei\\Desktop\\logo.png");
    QString dstPath("C:\\Users\\tujiawei\\Desktop\\xxx2.png");
    QString link("http://www.baidu.com/");
    QString linkText("www.baidu.com");

    QClipboard *clipboard = QApplication::clipboard();
    QPixmap pixmap(srcPath);
    QPixmap logo(logoPath);

    QPainter painter(&pixmap);
    painter.drawPixmap(pixmap.width() - logo.width(), 0, logo.width(), logo.height(), logo);
    pixmap.save(dstPath);

    int width = pixmap.width();
    int height = pixmap.height();
    QString html = QString("<html><body><img src=\"file:///%1\" width=\"%2\" height=\"%3\"/><br><a href=\"%4\">%5</a></body></html>").
            arg(dstPath).arg(width).arg(height).arg(link).arg(linkText);
    QMimeData *data = new QMimeData();
    data->setData("text/html", html.toLocal8Bit());
    clipboard->setMimeData(data);
