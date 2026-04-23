#include "unicode_util.hpp"

std::vector<std::string> split_graphemes(const std::string& text) {
    UErrorCode status = U_ZERO_ERROR;

    icu::UnicodeString u = icu::UnicodeString::fromUTF8(text);
    std::unique_ptr<icu::BreakIterator> it(
        icu::BreakIterator::createCharacterInstance(
            icu::Locale::getDefault(), status)
    );

    it->setText(u);

    std::vector<std::string> result;

    int32_t start = it->first();
    for (int32_t end = it->next();
         end != icu::BreakIterator::DONE;
         start = end, end = it->next()) {

        icu::UnicodeString part = u.tempSubStringBetween(start, end);
        std::string out;
        part.toUTF8String(out);
        result.push_back(out);
    }

    return result;
}

