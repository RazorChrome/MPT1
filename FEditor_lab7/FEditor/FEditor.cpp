#include "FEditor.h"
#include <regex>

bool FEditor::FracIsNull()
{
	regex fNumreg("-?0/?[1-9]*");
	if (regex_match(FEdit, fNumreg)) {
		return true;
	}
	else {
		return false;
	}
}

string FEditor::AddSign()
{
	if (FEdit[0] == '-') {
		FEdit.erase(0, 1);
	}
	else if (FEdit[0] != '0') {
		FEdit = "-" + FEdit;
	}
	return FEdit;
}

string FEditor::AddFracNumber(int a)
{
	if (FEdit.length() == 2) {
		if (FEdit[0] == '-' && FEdit[1] == 0) {
			FEdit.pop_back();
		}
	}
	else if (FEdit.length() == 1 && FEdit[0] == '0') {
		FEdit.pop_back();
	}

	FEdit.append(to_string(a));
	return FEdit;
}

string FEditor::AddNull()
{
	return AddFracNumber(0);
}

string FEditor::Backspace()
{
	if (FEdit.length() > 0) {
		FEdit.pop_back();
	}
	if ((FEdit == "") || (FEdit == "-")) {
		FEdit = Nul;
	}
	return FEdit;
}

string FEditor::Clear()
{
	FEdit = Nul;
	return FEdit;
}

FEditor::FEditor(string Cr)
{
	regex fNumreg("(0|-?[1-9][0-9]*)/[1-9][0-9]*");
	if (regex_match(Cr, fNumreg))
		FEdit = Cr;
}

string FEditor::GetStore()
{
	return FEdit;
}

void FEditor::SetStore(string a)
{
	regex fNumreg("(0|-?[1-9][0-9]*)/[1-9][0-9]*");
	if (regex_match(a, fNumreg))
		FEdit = a;
}

string FEditor::Edit(int a)
{
	string Result;

	if (a == 0) {
		Result = AddNull();
	}
	else if (a > 0 && a < 10) {
		Result = AddFracNumber(a);
	}
	else {
		Result = FEdit;
	}

	switch (a)
	{
	case Sign: //  + or -
		Result = AddSign();
		break;
	case Erase: // backSpace
		Result = Backspace();
		break;
	case RemoveAll:
		Result = Clear();
		break;
	case Separator:
		Result = AddSeparator();
	default:
		break;
	}

	return Result;
}

string FEditor::AddSeparator()
{
	if (FEdit.find('/') == -1) {
		FEdit += "/";
	}
	return FEdit;
}
