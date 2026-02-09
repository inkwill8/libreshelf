#include "../include/helper.h"
#include <cctype>

namespace Helper {
Genre StrToGenre(std::string genre) {
	if (genre == "Biography") return Genre::BIOGRAPHY;
	if (genre == "Memoir") return Genre::MEMOIR;
	if (genre == "Fantasy") return Genre::FANTASY;
	if (genre == "Sci-fi") return Genre::SCIFI;
	if (genre == "Young Adult") return Genre::YOUNG_ADULT;
	if (genre == "Historical Fiction") return Genre::HISTORICAL_FICTION;
	if (genre == "Romance") return Genre::ROMANCE;
	if (genre == "Horror") return Genre::HORROR;
	if (genre == "Thriller") return Genre::THRILLER;

	return Genre::UNKNOWN;
};

Status StrToStatus(std::string status) {
	for (auto& letter : status) {
	  letter = std::tolower(letter);
	}

	if (status == "want to read") return Status::WANT_TO_READ;
	if (status == "currently reading") return Status::CURRENTLY_READING;
	if (status == "finished") return Status::FINISHED;
	if (status == "did not finish") return Status::DID_NOT_FINISH;

	return Status::UNKNOWN;
};

std::string GenreToStr(Genre genre) {
	if (genre == Genre::BIOGRAPHY) return "Biography";
	if (genre == Genre::MEMOIR) return "Memoir";
	if (genre == Genre::FANTASY) return "Fantasy";
	if (genre == Genre::SCIFI) return "Sci-fi";
	if (genre == Genre::YOUNG_ADULT) return "Young Adult";
	if (genre == Genre::HISTORICAL_FICTION) return "Historical Fiction";
	if (genre == Genre::ROMANCE) return "Romance";
	if (genre == Genre::HORROR) return "Horror";
	if (genre == Genre::THRILLER) return "Thriller";

	return "Unknown";
};

std::string StatusToStr(Status status) {
	if (status == Status::WANT_TO_READ) return "Want to Read";
	if (status == Status::CURRENTLY_READING) return "Currently Reading";
	if (status == Status::FINISHED) return "Finished";
	if (status == Status::DID_NOT_FINISH) return "Did Not Finish";

	return "Unknown";
};

std::string ToLowercase(std::string word) {
	for (auto& letter : word) {
	  letter = std::tolower(letter);
	}

	return word;
};

// Makes a string where the first letter of each word is capitalized
std::string ToStandardFormat(std::string word) {
	std::string formattedWord = "";

	for (int i = 0; i < word.size(); i++) {
	  char letter = word[i];
	  char nextLetter = word[i + 1];

	  // Make sure the first letter is always capitalized
	  if (i = 0) {
		letter = static_cast<char>(std::toupper(letter));
		formattedWord.push_back(letter);
	  }

	  // If the letter is a space, i.e. it's a new word, capitalize the next letter
	  if (letter == " ") {
		formattedWord.push_back(letter);
		nextLetter = static_cast<char>(std::toupper(nextLetter));
	  }

	  // To ensure all letters still get added to return string
	  formattedWord.push_back(letter);
	}

	return formattedWord;
};

}

