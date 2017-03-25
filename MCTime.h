#define _CRT_SECURE_NO_WARNINGS

#define DEBUG(x) std::cout<<#x " = "<<x<<std::endl

#define TEACE(s) std::cerr<<#s<<std::endl;s

#define FIELD(a) char *a##_string;int a##_size


#ifndef MCTIME_H
#define MCTIME_H


#include<ctime>
#include<cstring>


namespace MCTIME {

	
	class MCTime {
	private:
		std::time_t t;
		std::tm local;
		char asciiRep[26];
		unsigned char lflag, aflag;
		void updateLocal() {
			if (!lflag) {
				local = *std::localtime(&t);
				lflag++;
			}
		}

		void updateAscii() {
			if (!aflag) {
				updateLocal();
				std::strcpy(asciiRep, std::asctime(&local));
				aflag++;
			}
		}

	public:
		MCTime() {
			mark();
		}

		void mark() {
			lflag = aflag = 0;
			std::time(&t);
		}

		const char *ascii() {
			updateAscii();
			return asciiRep;
		}


		int delta(MCTime *dt) const {
			return int(std::difftime(t,dt->t));
		}

		int daylightSavings() {
			updateLocal();
			return local.tm_isdst;
		}

		int dayOfYear() {
			updateLocal();
			return local.tm_yday;
		}

		int dayOfWeak() {
			updateLocal();
			return local.tm_wday;
		}

		int since1900() {
			updateLocal();
			return local.tm_year;
		}

		int month() {
			updateLocal();
			return local.tm_mon;
		}

		int hour() {
			updateLocal();
			return local.tm_hour;
		}

		int minute() {
			updateLocal();
			return local.tm_min;
		}

		int second() {
			updateLocal();
			return local.tm_sec;
		}

	};
}

#endif // !CTIME_H
