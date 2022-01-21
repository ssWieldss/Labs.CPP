#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <sstream>
#include <clocale>
#include <map>
#include <utility>

using namespace std;

pair<float, string> mult_two_different(float first, float second, string first_l, string second_l) {
	if (strcmp(first_l.c_str(), "kg") == 0 && strcmp(second_l.c_str(), "mps") == 0 ||
		strcmp(first_l.c_str(), "mps") == 0 && strcmp(second_l.c_str(), "kg") == 0) {
		return pair<float, string>(first * second, "kgmps");
	}
	else if (strcmp(first_l.c_str(), "kg") == 0 && strcmp(second_l.c_str(), "mpss") == 0 ||
		strcmp(first_l.c_str(), "mpss") == 0 && strcmp(second_l.c_str(), "kg") == 0) {
		return pair<float, string>(first * second, "n");
	}
	else if (strcmp(first_l.c_str(), "mps") == 0 && strcmp(second_l.c_str(), "kgmps") == 0 ||
		strcmp(first_l.c_str(), "kgmps") == 0 && strcmp(second_l.c_str(), "mps") == 0) {
		return pair<float, string>(first * second, "j");
	}
	throw invalid_argument("No such literal as result for multiplying " + first_l + " and " + second_l + " exist");
}

pair<float, string> divide_two_different(float first, float second, string first_l, string second_l) {
	if (strcmp(first_l.c_str(), "kgmps") == 0 && strcmp(second_l.c_str(), "kg") == 0) {
		return pair<float, string>(first / second, "mps");
	}
	else if (strcmp(first_l.c_str(), "kgmps") == 0 && strcmp(second_l.c_str(), "mps") == 0) {
		return pair<float, string>(first / second, "kg");
	}
	else if (strcmp(first_l.c_str(), "n") == 0 && strcmp(second_l.c_str(), "kg") == 0) {
		return pair<float, string>(first / second, "mpss");
	}
	else if (strcmp(first_l.c_str(), "n") == 0 && strcmp(second_l.c_str(), "mpss") == 0) {
		return pair<float, string>(first / second, "kg");
	}
	else if (strcmp(first_l.c_str(), "j") == 0 && strcmp(second_l.c_str(), "kgmps") == 0) {
		return pair<float, string>(first / second, "mps");
	}
	else if (strcmp(first_l.c_str(), "j") == 0 && strcmp(second_l.c_str(), "mps") == 0) {
		return pair<float, string>(first / second, "kgmps");
	}
	throw invalid_argument("No such literal as result for multiplying " + first_l + " and " + second_l + " exist");
}

pair<float, string> simple_calculate(string simple_operation) {

	regex sum("\\+");
	regex subtract("\\-");
	regex multiply("\\*");
	regex divide("[\\\\/]");

	regex literals("[A-Za-z]+");
	regex nums("[0-9]*[.]?[0-9]+");
	regex literal_before_operator("[A-Za-z]+[\\\/]");

	string final_literal;
	float result = 0.0;

	auto literals_begin = sregex_iterator(simple_operation.begin(), simple_operation.end(), literals);
	auto literals_end = sregex_iterator();

	int count = distance(literals_begin, literals_end);

	auto nums_begin = sregex_iterator(simple_operation.begin(), simple_operation.end(), nums);
	auto nums_end = sregex_iterator();

	if (distance(nums_begin, nums_end) != 2) {
		//îøèáêà, ÷èñåë äîëæíî áûòü äâîå
		throw invalid_argument("There should be two numbers");
	}

	float first_num = atof((*nums_begin).str().c_str());
	float second_num = atof((*(++nums_begin)).str().c_str());

	if (regex_search(simple_operation, sum)) {
		if (count == 0) {
			return pair<float, string>(first_num + second_num, "");
		}
		else if (count == 2) {
			string first = (*literals_begin).str();
			string second = (*(++literals_begin)).str();
			if (strcmp(first.c_str(), second.c_str())) {
				throw invalid_argument("Invalid sum operation: trying to sum two different values, differences in literals: " + first + " and " + second);
			}
			else {
				final_literal = (*literals_begin).str();
				return pair<float, string>(first_num + second_num, final_literal);
			}
		}
		else {
			throw invalid_argument("Invalid sum operation: trying to sum two different values, only one literal");
		}
	}
	else if (regex_search(simple_operation, subtract)) {
		if (count == 0) {
			return pair<float, string>(first_num - second_num, "");
		}
		else if (count == 2) {
			string first = (*literals_begin).str();
			string second = (*(++literals_begin)).str();
			if (strcmp(first.c_str(), second.c_str())) {
				throw invalid_argument("Invalid subtraction operation: trying to subtract two different values, differences in literals: " + first + " and " + second);
			}
			else {
				final_literal = (*literals_begin).str();
				return pair<float, string>(first_num - second_num, final_literal);
			}
		}
		else {
			throw invalid_argument("Invalid subtraction operation: trying to subtract two different values, only one literal");
		}
	}
	else if (regex_search(simple_operation, multiply)) {
		if (count == 0) {
			return pair<float, string>(first_num * second_num, "");
		}
		else if (count == 1) {
			string first_literal = (*literals_begin).str();
			return pair<float, string>(first_num * second_num, first_literal);
		}
		else if (count == 2) {
			string first_literal = (*literals_begin).str();
			string second_literal = (*(++literals_begin)).str();
			return mult_two_different(first_num, second_num, first_literal, second_literal);
		}
	}
	else if (regex_search(simple_operation, divide)) {
		if (count == 0) {
			return pair<float, string>(first_num / second_num, "");
		}
		else if (count == 1) {
			string first_literal = (*literals_begin).str();
			if (regex_search(simple_operation, literal_before_operator)) {
				return pair<float, string>(first_num / second_num, first_literal);
			}
			else {
				return divide_two_different(first_num, second_num, "", first_literal);
			}
		}
		else {
			string first_literal = (*literals_begin).str();
			string second_literal = (*(++literals_begin)).str();
			return divide_two_different(first_num, second_num, first_literal, second_literal);
		}
	}
	else {
		throw invalid_argument("Unknown operation");
	}
}

void resolve_expression(string& expression, regex& match_regex, pair<float, string>& result) {
	smatch found_exp;
	while (regex_search(expression, found_exp, match_regex, regex_constants::match_any)) {
		// cout << "Before: " << expression << endl;
		result = simple_calculate(found_exp[0].str());
		string to_swap = to_string(result.first) + result.second;
		expression = regex_replace(expression, match_regex, to_swap, regex_constants::format_first_only);
		// cout << "After: " << expression << endl << endl;
	}
}

void calculate_nonparentheses_expression(string expression, pair<float, string>& result) {
	regex multiplication("[A-Za-z0-9.]+[*][A-Za-z0-9.]+");
	regex division("[A-Za-z0-9.]+[\\/][A-Za-z0-9.]+");
	regex sum("[A-Za-z0-9.]+[+][A-Za-z0-9.]+");
	regex subtraction("[A-Za-z0-9.]+[-][A-Za-z0-9.]+");

	smatch found_exp;
	resolve_expression(expression, multiplication, result);
	resolve_expression(expression, division, result);
	resolve_expression(expression, sum, result);
	resolve_expression(expression, subtraction, result);
}

void resolve_parentheses(string& expression, pair<float, string>& result) {
	regex parentheses("([(])([^\\(\\)]+)([)])");
	smatch par_match;
	while (regex_search(expression, par_match, parentheses, regex_constants::match_any)) {
		calculate_nonparentheses_expression(par_match[2].str(), result);
		expression = regex_replace(expression, parentheses, to_string(result.first) + result.second, regex_constants::format_first_only);
	}
}

pair<float, string> calculate(string expression) {
	pair<float, string> result;
	resolve_parentheses(expression, result);
	calculate_nonparentheses_expression(expression, result);
	return result;
}

int main() {
	setlocale(LC_CTYPE, "Rus");
	ifstream file;
	file.open("input.txt");

	stringstream sread;
	sread << file.rdbuf();
	string text = sread.str();

	regex reg_for_yo_lower("[àåèîóûýþÿ]");
	regex reg_for_yo_upper("[ÀÅÈÎÓÛÝÞß]");
	regex reg_for_last_sogl("([À-ßà-ÿ¨¸]*[á-äæçê-íï-òô-ù])([^À-ßà-ÿ¨¸]|$)");

	ofstream write_file("output.txt");

	text = regex_replace(text, reg_for_yo_lower, "¸");
	text = regex_replace(text, reg_for_yo_upper, "¨");
	text = regex_replace(text, reg_for_last_sogl, "$1ú$2");
	write_file << text << endl;
	cout << text << endl << endl;

	file.close();
	write_file.close();

	string operation;
	cout << "Ââåäèòå îïåðàöèþ" << endl;
	getline(cin, operation);
	pair<float, string> res;
	try {
		res = calculate(operation);
		cout << res.first << res.second;
	}
	catch (invalid_argument ex) {
		cout << ex.what();
	}

	return 0;
}