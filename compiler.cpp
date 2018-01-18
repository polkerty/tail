#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	vector<string> registers = {"ax","bx","cx","dx","bp","sp","si","di"};
	
	map<string, int> srm;
	srm["inc"] = "\
	chapter inc_{r1}\
	\
	clear overflow_flag\
	\
	unless {r1}-0000 set {r1}-0000 return home\
	unless {r1}-0001 set {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-0010 set {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-0011 set {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-0100 set {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-0101 set {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-0110 set {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-0111 set {r1}-0111 clear {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-1000 set {r1}-1000 clear {r1}-0111 clear {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-1001 set {r1}-1001 clear {r1}-1000 clear {r1}-0111 clear {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-1010 set {r1}-1010 clear {r1}-1001 clear {r1}-1000 clear {r1}-0111 clear {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-1011 set {r1}-1011 clear {r1}-1010 clear {r1}-1001 clear {r1}-1000 clear {r1}-0111 clear {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-1100 set {r1}-1100 clear {r1}-1011 clear {r1}-1010 clear {r1}-1001 clear {r1}-1000 clear {r1}-0111 clear {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-1101 set {r1}-1101 clear {r1}-1100 clear {r1}-1011 clear {r1}-1010 clear {r1}-1001 clear {r1}-1000 clear {r1}-0111 clear {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-1110 set {r1}-1110 clear {r1}-1101 clear {r1}-1100 clear {r1}-1011 clear {r1}-1010 clear {r1}-1001 clear {r1}-1000 clear {r1}-0111 clear {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
	unless {r1}-1111 set {r1}-1111 clear {r1}-1110 clear {r1}-1101 clear {r1}-1100 clear {r1}-1011 clear {r1}-1010 clear {r1}-1001 clear {r1}-1000 clear {r1}-0111 clear {r1}-0110 clear {r1}-0101 clear {r1}-0100 clear {r1}-0011 clear {r1}-0010 clear {r1}-0001 clear {r1}-0000 return home\
";

srm["dec"] = "\
	chapter dec_{r1}\
	\
	clear overflow_flag\
	\
	if {r1}-0000 clear {r1}-0000 return home\
	if {r1}-0001 clear {r1}-0001 set {r1}-0000 return home\
	if {r1}-0010 clear {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-0011 clear {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-0100 clear {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-0101 clear {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-0110 clear {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-0111 clear {r1}-0111 set {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-1000 clear {r1}-1000 set {r1}-0111 set {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-1001 clear {r1}-1001 set {r1}-1000 set {r1}-0111 set {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-1010 clear {r1}-1010 set {r1}-1001 set {r1}-1000 set {r1}-0111 set {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-1011 clear {r1}-1011 set {r1}-1010 set {r1}-1001 set {r1}-1000 set {r1}-0111 set {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-1100 clear {r1}-1100 set {r1}-1011 set {r1}-1010 set {r1}-1001 set {r1}-1000 set {r1}-0111 set {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-1101 clear {r1}-1101 set {r1}-1100 set {r1}-1011 set {r1}-1010 set {r1}-1001 set {r1}-1000 set {r1}-0111 set {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-1110 clear {r1}-1110 set {r1}-1101 set {r1}-1100 set {r1}-1011 set {r1}-1010 set {r1}-1001 set {r1}-1000 set {r1}-0111 set {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	if {r1}-1111 clear {r1}-1111 set {r1}-1110 set {r1}-1101 set {r1}-1100 set {r1}-1011 set {r1}-1010 set {r1}-1001 set {r1}-1000 set {r1}-0111 set {r1}-0110 set {r1}-0101 set {r1}-0100 set {r1}-0011 set {r1}-0010 set {r1}-0001 set {r1}-0000 return home\
	\
	\
	set overflow_flag\
	visit set_{r1}\
	return home\
";





	map<string, int> drm;
	
	drm["mv"] = "\
		chapter {r1}_mov_{r2}\
		visit clear_{r2}\
		if {r1}-0000 set {r2}-0000\
		if {r1}-0001 set {r2}-0001\
		if {r1}-0010 set {r2}-0010\
		if {r1}-0011 set {r2}-0011\
		if {r1}-0100 set {r2}-0100\
		if {r1}-0101 set {r2}-0101\
		if {r1}-0110 set {r2}-0110\
		if {r1}-0111 set {r2}-0111\
		if {r1}-1000 set {r2}-1000\
		if {r1}-1001 set {r2}-1001\
		if {r1}-1010 set {r2}-1010\
		if {r1}-1011 set {r2}-1011\
		if {r1}-1100 set {r2}-1100\
		if {r1}-1101 set {r2}-1101\
		if {r1}-1110 set {r2}-1110\
		if {r1}-1111 set {r2}-1111\
		return home\
		";	
		
	string out = "
	
	return 0;
}