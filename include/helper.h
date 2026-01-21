#pragma once
#include <string>
#include "types.h"

namespace Helper {
Genre strToGenre(std::string genre) {
	if (genre == "Biography") return Genre::BIOGRAPHY;
	if (genre == "Memoir") return Genre::MEMOIR;
	if (genre == "Fantasy") return Genre::FANTASY;
	if (genre == "Sci-fi") return Genre::SCIFI;
	if (genre == "Young Adult") return Genre::YOUNG_ADULT;
	if (genre == "Historical Fiction") return Genre::HISTORICAL_FICTION;
	if (genre == "Romance") return Genre::ROMANCE;
	if (genre == "Horror") return Genre::HORROR;
	if (genre == "Thriller") return Genre::THRILLER;
};

Status strToStatus(std::string status) {
	if (status == "want to read") return Status::WANT_TO_READ;
	if (status == "currently reading") return Status::CURRENTLY_READING;
	if (status == "finished") return Status::FINISHED;
	if (status == "did not finish") return Status::DID_NOT_FINISH;
};
}
