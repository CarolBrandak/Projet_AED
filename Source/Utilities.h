#ifndef PROJECT_AED_UTILITIES_H
#define PROJECT_AED_UTILITIES_H

#include "Plane.h"

/**
* Boolean function thar compares to Employees based on their names
* @param e1 first Employee object that will be compared, passed by pointer
* @param e2 second Employee object that will be compared, passed by pointer
* @return if e1 has shorter name than e2, based on alphabetic order
*/
bool byEmployeeName(const Employee *e1, const Employee *e2);

/**
* Boolean function thar compares to Employees based on their ages
* @param e1 first Employee object that will be compared, passed by pointer
* @param e2 second Employee object that will be compared, passed by pointer
* @return if e1 has less age than e2
*/
bool byEmployeeAge(const Employee *e1, const Employee *e2);

/**
* Boolean function thar compares to Flights, based on their number of passengers
* @param f1 first flight that will be compared, passed by pointer
* @param f2 second flight object that will be compared, passed by pointer
* @return if f1 has less number of passengers than f2
*/
bool byNumberOfPassengers(const Flight *f1, const Flight *f2);

/**
* Boolean function thar compares to objects of this class, based on their total weight
* @param f1 first flight that will be compared, passed by pointer
* @param f2 second flight object that will be compared, passed by pointer
* @return if f1 has less total weight than f2
*/
bool byTotalWeight(const Flight *f1, const Flight *f2);

/**
* Boolean function thar compares to objects of this class, based on their date
* @param f1 first flight that will be compared, passed by pointer
* @param f2 second flight object that will be compared, passed by pointer
* @return if f1 occurs before f2
*/
bool byDate(const Flight *f1, const Flight *f2);

/**
* Boolean function thar compares to objects of this class, based on their duration
* @param f1 first flight that will be compared, passed by pointer
* @param f2 second flight object that will be compared, passed by pointer
* @return if f1 has less duration than f2
*/
bool byDuration(const Flight *f1, const Flight *f2);

/**
* Boolean function thar compares to objects of this class, based on their weight
* @param l1 first luggage that will be compared, passed by pointer
* @param l2 second luggage object that will be compared, passed by pointer
* @return if l1 has less weight than l2
*/
bool byWeight(const Luggage *l1, const Luggage *l2);

/**
* Boolean function thar compares to objects of this class, based on their volume
* @param l1 first luggage that will be compared, passed by pointer
* @param l2 second luggage object that will be compared, passed by pointer
* @return if l1 has less volume than l2
*/
bool byVolume(const Luggage *l1, const Luggage *l2);

/**
* Boolean function thar compares to objects of this class, based on their name
* @param p1 first passenger that will be compared, passed by pointer
* @param p2 second passenger that will be compared, passed by pointer
* @return if p1 has less name than p2, based on alphabetic order
*/
bool byPassengerName(const Passenger *p1, const Passenger *p2);

/**
* Boolean function thar compares to objects of this class, based on their age
* @param p1 first passenger that will be compared, passed by pointer
* @param p2 second passenger that will be compared, passed by pointer
* @return if p1 has less age than p2
*/
bool byAge(const Passenger *p1, const Passenger *p2);

/**
* Boolean function thar compares to objects of this class, based on their total luggage's weight
* @param p1 first passenger that will be compared, passed by pointer
* @param p2 second passenger that will be compared, passed by pointer
* @return if p1 has less luggage weight than p2
*/
bool byLuggage(const Passenger *p1, const Passenger *p2);

/**
* Boolean function thar compares to objects of this class, based on their total weight capacity
* @param p1 first plane that will be compared, passed by pointer
* @param p2 second plane that will be compared, passed by pointer
* @return if p1 has less weight capacity than p2
*/
bool byMaximumWeight(const Plane *p1, const Plane *p2);

/**
* Boolean function thar compares to objects of this class, based on their total passengers capacity
* @param p1 first plane that will be compared, passed by pointer
* @param p2 second plane that will be compared, passed by pointer
* @return if p1 has less capacity than p2
*/
bool byMaximumCapacity(const Plane *p1, const Plane *p2);

/**
* Boolean function thar compares to objects of this class, based on their total number of flights
* @param p1 first plane that will be compared, passed by pointer
* @param p2 second plane that will be compared, passed by pointer
* @return if p1 has less flights than p2
*/
bool byNumberOfFlights(const Plane *p1, const Plane *p2);

/**
* Boolean function thar compares to objects of this class, based on their total number of services
* @param p1 first plane that will be compared, passed by pointer
* @param p2 second plane that will be compared, passed by pointer
* @return if p1 has less services than p2
*/
bool byNumberOfServices(const Plane *p1, const Plane *p2) ;

/**
* Boolean function thar compares to objects of this class, based on their date
* @param s1 first service that will be compared, passed by pointer
* @param s2 second service that will be compared, passed by pointer
* @return if p1 is before p2
*/
bool byServiceDate(const Service *s1, const Service *s2);

/**
* Boolean function thar compares to objects of this class, based on their service type
* @param s1 first service that will be compared, passed by pointer
* @param s2 second service that will be compared, passed by pointer
* @return if s1 has less services type than s2
*/
bool byServiceType(const Service *s1, const Service *s2);

/**
* Boolean function thar compares to objects of this class, based on their distance to the airport
* @param t1 first transport that will be compared, passed by pointer
* @param t2 second transport that will be compared, passed by pointer
* @return if t1 has less distance than t2
*/
bool byDistance(const Transport *t1, const Transport *t2);

/**
* Boolean function thar compares to objects of this class, based on their type
* @param t1 first transport that will be compared, passed by pointer
* @param t2 second transport that will be compared, passed by pointer
* @return if t1 has less services than t2
*/
bool byTransportType(const Transport *t1, const Transport *t2);

/**
* Boolean function thar compares to objects of this class, based on their time
* @param t1 first transport that will be compared, passed by pointer
* @param t2 second transport that will be compared, passed by pointer
* @return if t1 has less time than t2
*/
bool byTransportTime(const Transport *t1, const Transport *t2);

#endif // PROJECT_AED_UTILITIES_H