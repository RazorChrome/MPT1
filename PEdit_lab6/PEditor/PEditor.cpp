#include "PEditor.h"
#include <string>
#include <regex>

using namespace std;

bool PEditor::NumberIsNull()
{
	regex pNumreg("-?0,?0*");
	if (regex_match(PEdit, pNumreg)) {
		return true;
	}
	else {
		return false;
	}
}

string PEditor::AddSign()
{

	if (PEdit[0] == '-') {
		PEdit.erase(PEdit.find('-'), 1);
	}
	else {
		PEdit = "-" + PEdit;
	}
	return PEdit; // ???
}



string  PEditor::AddPNumber(int a) 
{
	string d;

	if (PEdit == "0") {
		PEdit = "";
	}
	switch (a)
	{
	case 0: case 1: case 2: case 3:
	case 4: case 5: case 6:
	case 7: case 8: case 9:
		d = to_string(a);
		break;
	case 10:
		d = "A";
		break;
	case 11:
		d = "B";
		break;
	case 12:
		d = "C";
		break;
	case 13:
		d = "D";
		break;
	case 14:
		d = "E";
		break;
	case 15:
		d = "F";
		break;

	default:
		d = "";
		break;
	}
	PEdit.append(d);
	return PEdit;

}

string PEditor::AddNull()
{
	return AddPNumber(0);
}
string PEditor::BackSpace()
{
	int n;
	n = PEdit.length();
	PEdit.erase(n - 1, 1);//PEdit.erase(PEdit.length(), 2);
	if ((PEdit == "") || (PEdit == "-")) { // work
		PEdit = Nul;
	}

	return PEdit;
}
string PEditor::Clear()
{
	PEdit = Nul;
	return PEdit;

}

PEditor::PEditor(string Cr)
{
	regex pNumreg("-?(0|[1-9A-F][0-9A-F]*),?[0-9A-F]*");
	if (regex_match(Cr, pNumreg))
		PEdit = Cr;
}
string PEditor::GetStore() {
	return PEdit;
}
void PEditor::SetStore(string a) {
	regex pNumreg("-?(0|[1-9A-F][0-9A-F]*),?[0-9A-F]*");
	if (regex_match(a, pNumreg))
		PEdit = a;
}

string PEditor::Edit(int a)
{
	string Result;
	switch (a) {
	case 0:
		Result = AddNull();
		break;
	case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:
	case 9:case 10:case 11:case 12:case 13:case 14:case 15: // some shit again
		Result = AddPNumber(a);
		break;
	case Sign: // + or -
		Result = AddSign();
		break;
	case Erase: // backSpace
		Result = BackSpace();
		break;
	case RemoveAll: //clear
		Result = Clear();
		break;
	case Dot: //Dot
		Result = AddDot();
		break;
	default:
		Result = PEdit;
		break;

	}
	return Result;

}

string PEditor::AddDot()
{
	if (PEdit.find(',') == -1) {
		PEdit += ",";
	}
	return PEdit;
}

