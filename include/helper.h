#pragma once
#include "types.h"
#include <string>

namespace Helper {
Genre StrToGenre(std::string genre);
Status StrToStatus(std::string status);
std::string GenreToStr(Genre genre);
std::string StatusToStr(Status status);
std::string ToLowercase(std::string word);
std::string ToStandardFormat(std::string word);
std::string RemoveChars(std::string word, const std::string &charsToRemove);
std::string RemoveLeadingArticle(std::string word);
} // namespace Helper
