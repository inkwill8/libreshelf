#pragma once
#include <string>
#include "types.h"

namespace Helper {
	Genre StrToGenre(std::string genre);
	Status StrToStatus(std::string status);
	std::string GenreToStr(Genre genre);
	std::string StatusToStr(Status status);
	std::string ToLowercase(std::string word);
	std::string ToStandardFormat(std::string word);
}

