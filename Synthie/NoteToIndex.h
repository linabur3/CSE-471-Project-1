#pragma once
#include <string>

using namespace std;

//int NoteToIndex(const WCHAR* note) 
//{
//	if (note == TEXT("A#0"))
//		return 0;
//	if (note == TEXT("A0"))
//		return 1;
//	if (note == TEXT("A#1"))
//		return 2;
//	if (note == TEXT("A1"))
//		return 3;
//	if (note == TEXT("A#2"))
//		return 4;
//	if (note == TEXT("A2"))
//		return 5;
//	if (note == TEXT("A#3"))
//		return 6;
//	if (note == TEXT("A3"))
//		return 7;
//	if (note == TEXT("A#4"))
//		return 8;
//	if (note == TEXT("A4"))
//		return 9;
//	if (note == TEXT("A#5"))
//		return 10;
//	if (note == TEXT("A5"))
//		return 11;
//	if (note == TEXT("A#6"))
//		return 12;
//	if (note == TEXT("A6"))
//		return 13;
//	if (note == TEXT("A#7"))
//		return 14;
//	if (note == TEXT("A7"))
//		return 15;
//
//	if (note == TEXT("B0"))
//		return 16;
//	if (note == TEXT("B1"))
//		return 17;
//	if (note == TEXT("B2"))
//		return 18;
//	if (note == TEXT("B3"))
//		return 19;
//	if (note == TEXT("B4"))
//		return 20;
//	if (note == TEXT("B5"))
//		return 21;
//	if (note == TEXT("B6"))
//		return 22;
//	if (note == TEXT("B7"))
//		return 23;
//
//	if (note == TEXT("C#1"))
//		return 24;
//	if (note == TEXT("C1"))
//		return 25;
//	if (note == TEXT("C#2"))
//		return 26;
//	if (note == TEXT("C2"))
//		return 27;
//	if (note == TEXT("C#3"))
//		return 28;
//	if (note == TEXT("C3"))
//		return 29;
//	if (note == TEXT("C#4"))
//		return 30;
//	if (note == TEXT("C4"))
//		return 31;
//	if (note == TEXT("C#5"))
//		return 32;
//	if (note == TEXT("C5"))
//		return 33;
//	if (note == TEXT("C#6"))
//		return 34;
//	if (note == TEXT("C6"))
//		return 35;
//	if (note == TEXT("C#7"))
//		return 36;
//	if (note == TEXT("C7"))
//		return 37;
//	if (note == TEXT("C8"))
//		return 38;
//
//	if (note == TEXT("D#1"))
//		return 39;
//	if (note == TEXT("D1"))
//		return 40;
//	if (note == TEXT("D#2"))
//		return 41;
//	if (note == TEXT("D2"))
//		return 42;
//	if (note == TEXT("D#3"))
//		return 43;
//	if (note == TEXT("D3"))
//		return 44;
//	if (note == TEXT("D#4"))
//		return 45;
//	if (note == TEXT("D4"))
//		return 46;
//	if (note == TEXT("D#5"))
//		return 47;
//	if (note == TEXT("D5"))
//		return 48;
//	if (note == TEXT("D#6"))
//		return 49;
//	if (note == TEXT("D6"))
//		return 50;
//	if (note == TEXT("D#7"))
//		return 51;
//	if (note == TEXT("D7"))
//		return 52;
//
//	if (note == TEXT("E1"))
//		return 53;
//	if (note == TEXT("E2"))
//		return 54;
//	if (note == TEXT("E3"))
//		return 55;
//	if (note == TEXT("E4"))
//		return 56;
//	if (note == TEXT("E5"))
//		return 57;
//	if (note == TEXT("E6"))
//		return 58;
//	if (note == TEXT("E7"))
//		return 59;
//
//
//	if (note == TEXT("F#1"))
//		return 60;
//	if (note == TEXT("F1"))
//		return 61;
//	if (note == TEXT("F#2"))
//		return 62;
//	if (note == TEXT("F2"))
//		return 63;
//	if (note == TEXT("F#3"))
//		return 64;
//	if (note == TEXT("F3"))
//		return 65;
//	if (note == TEXT("F#4"))
//		return 66;
//	if (note == TEXT("F4"))
//		return 67;
//	if (note == TEXT("F#5"))
//		return 68;
//	if (note == TEXT("F5"))
//		return 69;
//	if (note == TEXT("F#6"))
//		return 70;
//	if (note == TEXT("F6"))
//		return 71;
//	if (note == TEXT("F#7"))
//		return 72;
//	if (note == TEXT("F7"))
//		return 73;
//
//	if (note == TEXT("G#1"))
//		return 74;
//	if (note == TEXT("G1"))
//		return 75;
//	if (note == TEXT("G#2"))
//		return 76;
//	if (note == TEXT("G2"))
//		return 77;
//	if (note == TEXT("G#3"))
//		return 78;
//	if (note == TEXT("G3"))
//		return 79;
//	if (note == TEXT("G#4"))
//		return 80;
//	if (note == TEXT("G4"))
//		return 81;
//	if (note == TEXT("G#5"))
//		return 82;
//	if (note == TEXT("G5"))
//		return 83;
//	if (note == TEXT("G#6"))
//		return 84;
//	if (note == TEXT("G6"))
//		return 85;
//	if (note == TEXT("G#7"))
//		return 86;
//	if (note == TEXT("G7"))
//		return 87;
//
//	return 0;
//}

//
// Name :         Notes.h
// Description :  Header file with consts for notes to frequency conversions.
//

#pragma once

struct Indexes
{
	const TCHAR* name;
	int index;
};

const Indexes indexes[] = { 
	{TEXT("A#0"), 0},
	{TEXT("A0"),  1},
	{TEXT("A#1"), 2},
	{TEXT("A1"),  3},
	{TEXT("A#2"), 4},
	{TEXT("A2"),  5},
	{TEXT("A#3"), 6},
	{TEXT("A3"),  7},
	{TEXT("A#4"), 8},
	{TEXT("A4"),  9},
	{TEXT("A#5"), 10},
	{TEXT("A5"),  11},
	{TEXT("A#6"), 12},
	{TEXT("A6"),  13},
	{TEXT("A#7"), 14},
	{TEXT("A7"),  15},
	{TEXT("B0"), 16},
	{TEXT("B1"),  17},
	{TEXT("B2"), 18},
	{TEXT("B3"),  19},
	{TEXT("B4"), 20},
	{TEXT("B5"),  21},
	{TEXT("B6"), 22},
	{TEXT("B7"),  23},
	{TEXT("C#1"), 24},
	{TEXT("C1"),  25},
	{TEXT("C#2"), 26},
	{TEXT("C2"),  27},
	{TEXT("C#3"), 28},
	{TEXT("C3"),  29},
	{TEXT("C#4"), 30},
	{TEXT("C4"),  31},
	{TEXT("C#5"), 32},
	{TEXT("C5"),  33},
	{TEXT("C#6"), 34},
	{TEXT("C6"),  35},
	{TEXT("C#7"), 36},
	{TEXT("C7"),  37},
	{TEXT("C8"), 38},
	{TEXT("D#1"), 39},
	{TEXT("D1"),  40},
	{TEXT("D#2"), 41},
	{TEXT("D2"),  42},
	{TEXT("D#3"), 43},
	{TEXT("D3"),  44},
	{TEXT("D#4"), 45},
	{TEXT("D4"),  46},
	{TEXT("D#5"), 47},
	{TEXT("D5"),  48},
	{TEXT("D#6"), 49},
	{TEXT("D6"),  50},
	{TEXT("D#7"), 51},
	{TEXT("D7"),  52},
	{TEXT("E1"),  53},
	{TEXT("E2"), 54},
	{TEXT("E3"),  55},
	{TEXT("E4"), 56},
	{TEXT("E5"),  57},
	{TEXT("E6"), 58},
	{TEXT("E7"),  59},
	{TEXT("F#1"), 60},
	{TEXT("F1"),  61},
	{TEXT("F#2"), 62},
	{TEXT("F2"),  63},
	{TEXT("F#3"), 64},
	{TEXT("F3"),  65},
	{TEXT("F#4"), 66},
	{TEXT("F4"),  67},
	{TEXT("F#5"), 68},
	{TEXT("F5"),  69},
	{TEXT("F#6"), 70},
	{TEXT("F6"),  71},
	{TEXT("F#7"), 72},
	{TEXT("F7"),  73},
	{TEXT("G#1"), 74},
	{TEXT("G1"),  75},
	{TEXT("G#2"), 76},
	{TEXT("G2"),  77},
	{TEXT("G#3"), 78},
	{TEXT("G3"),  79},
	{TEXT("G#4"), 80},
	{TEXT("G4"),  81},
	{TEXT("G#5"), 82},
	{TEXT("G5"),  83},
	{TEXT("G#6"), 84},
	{TEXT("G6"),  85},
	{TEXT("G#7"), 86},
	{TEXT("G7"),  87},

};


double NoteToIndex(const WCHAR* name);