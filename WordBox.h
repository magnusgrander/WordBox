#ifndef WORDBOX_H
#define WORDBOX_H

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <clocale>
#include <locale>

class WordBox {
public:
    using Row = std::vector<std::wstring>;

    WordBox(wchar_t h = L'-', wchar_t v = L'|', wchar_t c = L'+');

    void setAlign(unsigned i, bool left);
    bool isAligned(unsigned i) const;
    wchar_t vertical() const;
    wchar_t horizontal() const;

    void addContent(const std::wstring& content);
    void newRow();

    template <typename Iterator>
    void addRow(Iterator begin, Iterator end);

    template <typename Container>
    void addRow(const Container& container);

    const std::vector<Row>& getRows() const;
    void prepare() const;
    std::wstring ruler() const;
    int getWidth(unsigned i) const;
    bool hasRuler() const;
    void toggleRuler();
    void textLength(int l);
    void print(void);

private:
    wchar_t _h;
    wchar_t _v;
    wchar_t _c;
    mutable bool _hasRuler;
    Row _current;
    std::vector<Row> _rows;
    mutable std::vector<unsigned> _width;
    mutable std::map<unsigned, bool> _align;
    int maxrowlength = 20;

    static std::wstring repeat(unsigned times, wchar_t c);
    unsigned columnCount() const;
    std::wstring format(const std::wstring& content) const;
    void calculateWidths() const;
    void configureAlignment() const;
};



#endif // WORDBOX_H
