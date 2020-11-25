#include "util.h"

tm Util::string2time(string str){
    const char* charstar = str.c_str();
    int tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec;
    tm tm1 = {0};
	sscanf(charstar,"%4d-%2d-%2d",&tm1.tm_year,&tm1.tm_mon,&tm1.tm_mday);
    return tm1;
}
string Util::time2string(tm tm1){
    char buffer[80];
    char b_mon[5];
    if (tm1.tm_mon < 10){
        sprintf(b_mon,"0%d", tm1.tm_mon);
    }
    else{
        sprintf(b_mon,"%d", tm1.tm_mon);
    }
    char b_day[5];
    if (tm1.tm_mday < 10){
        sprintf(b_day,"0%d", tm1.tm_mday);
    }
    else{
        sprintf(b_day,"%d", tm1.tm_mday);
    }
    sprintf(buffer, "%4d-%s-%s",tm1.tm_year,b_mon,b_day);
    string s(buffer);
    return s;
}
int Util::compare(tm tm1, tm tm2){
    if (tm1.tm_year > tm2.tm_year) return 1;
    else if (tm1.tm_year < tm2.tm_year) return -1;
    else 
    if (tm1.tm_mon > tm2.tm_mon) return 1;
    else if (tm1.tm_mon < tm2.tm_mon) return -1; 
    else
    if (tm1.tm_mday > tm2.tm_mday) return 1;
    else if (tm1.tm_mday < tm2.tm_mday) return -1;  
    else return 0;
}
bool Util::isEqual(tm tm1, tm tm2){
    if (tm1.tm_year != tm2.tm_year) return false;
    if (tm1.tm_mon != tm2.tm_mon) return false;
    if (tm1.tm_mday != tm2.tm_mday) return false;
    return true;
}

/** @brief Function get today.
 *  
 *  Function get today, read date of today from device then convert to a string.
 *  @return date of today with format dd/mm/yyyy.
 *  @author Ly Truong (truonglehaily)
 */
string Util::GetToday(){
    time_t curr_time;
	tm * curr_tm;
	char date_string[10];
	string s = "";
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	strftime(date_string, 50, "%d/%m/%Y", curr_tm);
	for(char i:date_string){
		s += i;
	}
	return s;
}

/** @brief Function copy file.
 *  
 *  Function copy file, read a file from folder then write this to another folder.
 *  @return 0 if copy file success, 1 if error.
 *  @author Ly Truong (truonglehaily)
 */
//https://stackoverflow.com/questions/3512271/how-to-copy-text-file-in-c-or-c
int Util::CopyFile(string from, string to, int select){
    string fileName = "";
    switch (select){
        case 1:
            fileName = "Customers.data";
            break;
        case 2:
            fileName = "Categories.data";
            break;
        case 3:
            fileName = "Employees.data";
            break;
        case 4:
            fileName = "Products.data";
            break;
        case 5:
            fileName = "Orders.data";
            break;
        case 6:
            fileName = "OrderDetails.data";
            break;
        case 7:
            fileName = "Shippers.data";
            break;
        case 8:
            fileName = "Suppliers.data";
            break;
    default:
        break;
    }

    from = from + fileName;
    to = to + fileName;
    try{
        std::ifstream inFile(from);
        std::ofstream outFile(to);

        outFile << inFile.rdbuf();
        return 0;
    }
    catch(...){
        return 1;
    }
}