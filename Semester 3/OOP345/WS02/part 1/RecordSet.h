/****************************************************************
Name: Jia Hua Zou
ID: 114383193
Date: Oct 8,2020.
Lab 2

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef SDDS_RECORDSET_H_
#define SDDS_RECORDSET_H_

namespace sdds {

	class RecordSet
	{
	private:
		size_t counter{ 0 };
		std::string* file{ nullptr };

	public:
		RecordSet();
		RecordSet(const std::string& );
		RecordSet(const RecordSet&); //copy constructor
		RecordSet(RecordSet&&); //Move constructor
		~RecordSet();

		size_t size() const;
		std::string getRecord(size_t);

		RecordSet& operator =(const RecordSet&); //copy assignment
		RecordSet& operator =(RecordSet&&); //Move assignment
	};
}



#endif // !SDDS_RECORDSET_H_