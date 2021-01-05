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
		std::for_each(m_song_collection.begin(), m_song_collection.end(), [&](const Song& theSong)
			{ out << theSong << std::endl; });

		auto total_time = std::accumulate(m_song_collection.begin(), m_song_collection.end(), 0, [](const size_t num, const Song src)
			{return num + src.m_length; });
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::right << std::setw(77) << "Total Listening Time: "
			<< (total_time / 3600) << ":" //hr
			<< ((total_time % 3600) / 60) << ":" //min
			<< ((total_time % 3600) % 60) //sec
			<< " |" << std::endl;
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
			<< " | " << std::setprecision(3) << theSong.m_price << " |" << std::setfill(' ');
		return out;
	}

	void SongCollection::sort(const std::string& src) {
		if (src == "title")
		{
			std::sort(m_song_collection.begin(), m_song_collection.end(), [](Song src1, Song src2)
				{return src1.m_title < src2.m_title; });
		}
		else if (src == "length")
		{
			std::stable_sort(m_song_collection.begin(), m_song_collection.end(), [](Song src1, Song src2)
				{return src1.m_length < src2.m_length; });
		}
	}

	void SongCollection::cleanAlbum() {
		//IT NEEDS TO RETURN SOMETHING.
		std::transform(m_song_collection.begin(), m_song_collection.end(), m_song_collection.begin(), [](Song& src)
			{
				if (src.m_album == "[None]") src.m_album = " ";
				return src;
			});
	}

	bool SongCollection::inCollection(const std::string& src_artist) const {
		auto result = std::find_if(m_song_collection.begin(), m_song_collection.end(), [&](const Song& src)
			{
				return src.m_artist == src_artist ? true : false;
			});
		return result != m_song_collection.end();
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string& src_artist) const {
		auto count = std::count_if(m_song_collection.begin(), m_song_collection.end(), [&](const Song& song) {
			return song.m_artist == src_artist;
			});

		std::list<Song> filterSongs(count);
		std::copy_if(m_song_collection.begin(), m_song_collection.end(), filterSongs.begin(), [&](const Song& song) {
			return song.m_artist == src_artist;
			});
		return filterSongs;
	}
}