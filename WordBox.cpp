#include "WordBox.h"

WordBox::WordBox(wchar_t h, wchar_t v, wchar_t c)
    : _h(h), _v(v), _c(c), _hasRuler(true) {
    std::setlocale(LC_ALL, "");
}

void WordBox::setAlign(unsigned i, bool left) {
    _align[i] = left;
}

bool WordBox::isAligned(unsigned i) const { return _align[i]; }
wchar_t WordBox::vertical() const { return _v; }
wchar_t WordBox::horizontal() const { return _h; }

void WordBox::addContent(const std::wstring& content) { 
    _current.push_back(format(content)); 
}

void WordBox::newRow() {
    _rows.push_back(_current);
    _current.clear();
}

template <typename Iterator>
void WordBox::addRow(Iterator begin, Iterator end) {
    for (auto i = begin; i != end; ++i) {
        addContent(*i);
    }
    newRow();
}

template <typename Container>
void WordBox::addRow(const Container& container) {
    addRow(container.begin(), container.end());
}

const std::vector<WordBox::Row>& WordBox::getRows() const { return _rows; }

void WordBox::prepare() const {
    calculateWidths();
    configureAlignment();
}

std::wstring WordBox::ruler() const {
    std::wstring result;
    result += _c;
    for (const auto& width : _width) {
        result += repeat(width, _h);
        result += _c;
    }
    return result;
}

int WordBox::getWidth(unsigned i) const { return _width[i]; }
bool WordBox::hasRuler() const { return _hasRuler; }
void WordBox::toggleRuler() { _hasRuler = !_hasRuler; }

void WordBox::print(void) {
    int count = 0;
    if (_rows.empty()) return;

    prepare();
    if (hasRuler()) {
        std::wcout << ruler() << L"\n";
    }

    for (const auto& row : _rows) {
        std::wcout << vertical();
        for (unsigned i = 0; i < row.size(); ++i) {
            auto alignment = isAligned(i) ? std::left : std::right;
            std::wcout << std::setw(getWidth(i)) << alignment << row[i];
            std::wcout << vertical();
        }
        std::wcout << L"\n";
        if (hasRuler() && count == 0 ) {
            std::wcout << ruler() << L"\n";
        }   
        
        count++;    
    }
    
    if (hasRuler() && _rows.size() > 1) {
        std::wcout << ruler() << L"\n";
    }
    
}



std::wstring WordBox::repeat(unsigned times, wchar_t c) {
    return std::wstring(times, c);
}

unsigned WordBox::columnCount() const { return _rows.empty() ? 0 : _rows[0].size(); }

std::wstring WordBox::format(const std::wstring& content) const {
    std::wstring formatted = L" " + content + L" ";
    if (formatted.length() > maxrowlength+2) {
        formatted = formatted.substr(0, maxrowlength) + L"...";
    }
    return formatted;
}

void WordBox::textLength(int l) {
	maxrowlength = l;
}

void WordBox::calculateWidths() const {
    if (_rows.empty()) return;
    _width.assign(columnCount(), 0);
    for (const auto& row : _rows) {
        for (unsigned i = 0; i < row.size(); ++i) {
            _width[i] = std::max(_width[i], static_cast<unsigned>(row[i].length()));
        }
    }
}

void WordBox::configureAlignment() const {
    if (_rows.empty()) return;
    for (unsigned i = 0; i < columnCount(); ++i) {
        if (_align.find(i) == _align.end()) {
            _align[i] = true; // Default to left alignment
        }
    }
}


