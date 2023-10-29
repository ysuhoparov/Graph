#ifndef ABOUT_H
#define ABOUT_H


class About
{
public:
    const char* about{ R"(
Необходимо разработать десктопное приложение,
принимающее данные по сетевому протоколу и
выполняющее визуализацию этих данных.
Требования
1. Приложение включает в себя три окна.
1) Главное окно. Включает главное меню. Всего 2 позиции:
- Wave Viewer
- About
Пример:
2) Окно About — произвольная текстовая информация (о
версии ПО, создателе и т. п.)
1
3) Окно Wave Viewer. На нем должны быть расположены
виджеты:
- график, на котором должна быть отображена кривая
(wave), построенная на основании данных, полученных по
сетевому протоколу;
- по данным кривой должны быть вычислены
а) максимальное значение;
б) медиана;
- вычисленные значения должны быть отражены на
виджете (в виде маркеров на графике, либо в логе, либо в
строке состояния):
- [опционально] кнопка «Старт» («Стоп») для запуска
(остановки) приема данных по сетевому протоколу;
- [опционально] строка состояния, либо поле для вывода
лога.  )" };

    const char* aboutF{ R"(
  Формат данных, принимаемых по сетевому протоколу.
1) Данные принимаются по UDP-протоколу
2) IP-адрес 127.0.0.1 (localhost), port 10002
3) Размер дейтаграммы 8192 Байт
4) Данные содержат 4096 сэмплов в формате int16. По этим
сэмплам и выстраивается кривая на графике окна Wave
Viewer. По оси Y откладываются значения сэмплов, по оси X
— их порядковый номер.
5) При получении новой «пачки» данных (дейтаграммы)
кривая на графике полностью обновляется
(перестраивается), максимальное значение и медиана
пересчитываются заново.
3. Рекомендуемые технологии для реализации
1) Qt Widgets — работа с окнами, виджетами форм GUI
2) Qwt, QChart, QCustomPlot, ROOT и другие (на самом
деле, вариантов масса) — работа с визуализацией
данных га графике
3) Qt Network, boost.asio — работа с сетевыми
протоколами )" };

} ab;

#endif // ABOUT_H