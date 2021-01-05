#include "SongCollection.h"

namespace sdds {
	SongCollection::SongCollection(const char* filename) {
		std::ifstream file(filename);
		if (!file)
		{
			throw "ERROR: Cannot open file";
		}
		while (file)
		{
			Song song;
			std::string song_infor{ '\0' };
			std::string temp{ '\0' };
			getline(file, song_infor);
			if (file) {

				song.m_title = song_infor.substr(0, 25);
				trim(song.m_title);
				song.m_artist = song_infor.substr(25, 25);
				trim(song.m_artist);
				song.m_album = song_infor.substr(50, 25);
				trim(song.m_album);

				try
				{
					//yr
					temp = song_infor.substr(75, 5);
					trim(temp);
					song.m_year = std::stoi(temp);
				}
				catch (...)
				{
					song.m_year = 0;
				}
				//length
				temp = song_infor.substr(80, 5);
				trim(temp);
				song.m_length = std::stoi(temp);

				//price
				temp = song_infor.substr(85, 5);
				trim(temp);
				song.m_price = std::stod(temp);

				m_song_collection.push_back(song);
			}
		}
		file.close();
	}

	void SongCollection::trim(std::string& src) {
		size_t start = src.find_first_not_of(" ");
		src = (start == std::string::npos) ? "" : src.substr(start);
		size_t end = src.find_last_not_of(" ");
		src = (end == std::string::npos) ? "" : src.substr(0, end + 1);
	}

	void SongCollection::display(std::ostream& out) const {
		std::for_each(m_song_collection.begin(), m_song_collection.end(), [&](const Song& theSong) { out << theSong; });
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::left << std::setw(20) << theSong.m_title
			<< " | " << std::left << std::setw(15) << theSong.m_artist
			<< " | " << std::left << std::setw(20) << theSong.m_album;

		if (theSong.m_year == 0) {
			out << " | " << std::right << std::setw(9);
		}
		else
		{
			out << " | " << std::right << std::setw(6) << theSong.m_year;
		}
		out << " | " << std::setprecision(0) << (theSong.m_length / 60) << ":" << std::setw(2) << std::setfill('0') << (theSong.m_length % 60)
			<< " | " << std::setprecision(3) << theSong.m_price << " |" << std::setfill(' ') << std::endl;
		return out;
	}
}