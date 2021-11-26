#ifndef DATE_H
#define DATE_H

/**
 * A class that represents a Date
 */
class Date {

    private:
        int day;
        int month;
        int year;

    public:
        /**
        * A default constructor of class Date.
        */
        Date();

        /**
         * Main constructor
         * @param day Date's day, a int passed by value
         * @param month Date's month, a int passed by value
         * @param year Date's year, a int passed by value
         */
        Date(int day, int month, int year);

        /**
         * Return Date's day
         * @return a int, containing date's day
         */
        int getDay();

        /**
         * Return Date's month
         * @return a int, containing date's month
         */
        int getMonth();

        /**
         * Return Date's year
         * @return a int, containing date's year
         */
        int getYear();

        /**
         * Set Date day
         * @param day Date's new day, a int passed by value
         */
        void setDay(int day);

        /**
         * Set Date month
         * @param month Date's new month, a int passed by value
         */
        void setMonth(int month);

        /**
         * Set Date year
         * @param year Date's new year, a int passed by value
         */
        void setYear(int year);

}

#endif //DATE_H
