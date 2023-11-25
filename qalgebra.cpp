/* ***************************************************************************************************** *
 * Copyright (C) 2023 Matthieu Charrier <matthieu.charrier.pro@gmail.com>. ***************************** *
 * All rights reserved. ******************************************************************************** *
 * This file is part of the project 'QA - Quantitative Analytics'. ************************************* *
 * Hence the latter remains the exclusive property of its author. ************************************** *
 * Accordingly, no part of this document may be used in any form for professional or commercial purposes *
 * without the express permission of Matthieu Charrier. ************************************************ *
 * ***************************************************************************************************** */

#include <exception>
#include <fstream>

#include <qalgebra.hpp>

amount_t operator+(const amount_t& x) { return {"{\"0\":0,\"1\":" + x.s + "}"}; }
amount_t operator+(const amount_t& x, const amount_t& y) { return {"{\"0\":1,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
amount_t operator+(const amount_t& x, double y) { return {"{\"0\":2,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
amount_t operator+(double x, const amount_t& y) { return {"{\"0\":3,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
amount_t operator-(const amount_t& x) { return {"{\"0\":32,\"1\":" + x.s + "}"}; }
amount_t operator-(const amount_t& x, const amount_t& y) { return {"{\"0\":4,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
amount_t operator-(const amount_t& x, double y) { return {"{\"0\":5,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
amount_t operator-(double x, const amount_t& y) { return {"{\"0\":6,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
amount_t operator*(const amount_t& x, const amount_t& y) { return {"{\"0\":7,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
amount_t operator*(const amount_t& x, double y) { return {"{\"0\":8,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
amount_t operator*(double x, const amount_t& y) { return {"{\"0\":9,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
amount_t operator/(const amount_t& x, const amount_t& y) { return {"{\"0\":10,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
amount_t operator/(const amount_t& x, double y) { return {"{\"0\":11,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
amount_t operator/(double x, const amount_t& y) { return {"{\"0\":12,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
event_t operator<=(const amount_t& x, const amount_t& y) { return {"{\"0\":0,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
event_t operator<=(const amount_t& x, double y) { return {"{\"0\":1,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
event_t operator<=(double x, const amount_t& y) { return {"{\"0\":2,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
event_t operator<(const amount_t& x, const amount_t& y) { return {"{\"0\":3,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
event_t operator<(const amount_t& x, double y) { return {"{\"0\":4,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
event_t operator<(double x, const amount_t& y) { return {"{\"0\":5,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
event_t operator>=(const amount_t& x, const amount_t& y) { return {"{\"0\":6,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
event_t operator>=(const amount_t& x, double y) { return {"{\"0\":7,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
event_t operator>=(double x, const amount_t& y) { return {"{\"0\":8,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
event_t operator>(const amount_t& x, const amount_t& y) { return {"{\"0\":9,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
event_t operator>(const amount_t& x, double y) { return {"{\"0\":20,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
event_t operator>(double x, const amount_t& y) { return {"{\"0\":10,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
event_t operator==(const amount_t& x, const amount_t& y) { return {"{\"0\":11,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
event_t operator==(const amount_t& x, double y) { return {"{\"0\":12,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
event_t operator==(double x, const amount_t& y) { return {"{\"0\":13,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
event_t operator!=(const amount_t& x, const amount_t& y) { return {"{\"0\":14,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
event_t operator!=(const amount_t& x, double y) { return {"{\"0\":15,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
event_t operator!=(double x, const amount_t& y) { return {"{\"0\":16,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
event_t operator&&(const event_t& x, const event_t& y) { return {"{\"0\":17,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
event_t operator||(const event_t& x, const event_t& y) { return {"{\"0\":18,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
event_t operator!(const event_t& x) { return {"{\"0\":19,\"1\":" + x.s + "}"}; }
cashflow_t operator&(const cashflow_t& x, const cashflow_t& y) { return {"{\"0\":0,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }

amount_t SPOT(const ticker_t& t, const date_t& d, const date_shift_t& ds) { return {"{\"0\":13,\"1\":\"" + t + "\",\"2\":\"" + d + "\",\"3\":\"" + ds + "\"}"}; }
amount_t SPOT_COMPOSITE(const ticker_t& t, const date_t& d, const currency_t& c, const date_shift_t& ds) { return {"{\"0\":13,\"1\":\"" + t + "\",\"2\":\"" + d + "\",\"3\":\"" + c + "\",\"4\":\"" + ds + "\"}"}; }
amount_t REF(const std::string& n, double x) { return {"{\"0\":14,\"1\":" + n + ",\"2\":" + std::to_string(x) + "}"}; }
amount_t CST(double x) { return {"{\"0\":15,\"1\":" + std::to_string(x) + "}"}; }
amount_t AMOUNT(const ticker_t& t) { return {"{\"0\":16,\"1\":\"" + t + "\"}"}; }
amount_t POW(const amount_t& x, unsigned n) { return {"{\"0\":17,\"1\":" + x.s + ",\"2\":" + std::to_string(n) + "}"}; }
amount_t ABS(const amount_t& x) { return {"{\"0\":18,\"1\":" + x.s + "}"}; }
amount_t COS(const amount_t& x) { return {"{\"0\":19,\"1\":" + x.s + "}"}; }
amount_t SIN(const amount_t& x) { return {"{\"0\":20,\"1\":" + x.s + "}"}; }
amount_t TAN(const amount_t& x) { return {"{\"0\":21,\"1\":" + x.s + "}"}; }
amount_t EXP(const amount_t& x) { return {"{\"0\":22,\"1\":" + x.s + "}"}; }
amount_t LOG(const amount_t& x) { return {"{\"0\":23,\"1\":" + x.s + "}"}; }
amount_t SQRT(const amount_t& x) { return {"{\"0\":24,\"1\":" + x.s + "}"}; }
amount_t MAX(const amount_t& x, const amount_t& y) { return {"{\"0\":25,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
amount_t MAX(const amount_t& x, double y) { return {"{\"0\":26,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
amount_t MAX(double x, const amount_t& y) { return {"{\"0\":27,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
amount_t MIN(const amount_t& x, const amount_t& y) { return {"{\"0\":28,\"1\":" + x.s + ",\"2\":" + y.s + "}"}; }
amount_t MIN(const amount_t& x, double y) { return {"{\"0\":29,\"1\":" + x.s + ",\"2\":" + std::to_string(y) + "}"}; }
amount_t MIN(double x, const amount_t& y) { return {"{\"0\":30,\"1\":" + std::to_string(x) + ",\"2\":" + y.s + "}"}; }
event_t CST(bool x) { return {"{\"0\":21,\"1\":" + std::to_string(x) + "}"}; }
cashflow_t BUY(const date_t& d, double q, const cashflow_t& x) { return {"{\"0\":1,\"1\":\"" + d + "\",\"2\":" + std::to_string(q) + ",\"3\":" + x.s + ",\"4\":" + (q > 0 ? "1" : "-1") + "}"}; }
cashflow_t BUY(const date_t& d, const cashflow_t& x) { return BUY(d, 1, x); }
cashflow_t SELL(const date_t& d, double q, const cashflow_t& x) { return {"{\"0\":1,\"1\":\"" + d + "\",\"2\":" + std::to_string(q) + ",\"3\":" + x.s + (q > 0 ? "1" : "-1") + "}"}; }
cashflow_t SELL(const date_t& d, const cashflow_t& x) { return SELL(d, 1, x); }
cashflow_t END(void) { return {"{\"0\":2}"}; }
cashflow_t PAY(const amount_t& x, const date_t& d, const currency_t& c) { return {"{\"0\":3,\"1\":" + x.s + ",\"2\":\"" + d + "\",\"3\":\"" + c + "\",\"4\":1}"}; }
cashflow_t PAY(double x, const date_t& d, const currency_t& c) { return PAY(CST(x), d, c); }
cashflow_t RECEIVE(const amount_t& x, const date_t& d, const currency_t& c) { return {"{\"0\":3,\"1\":" + x.s + ",\"2\":\"" + d + "\",\"3\":\"" + c + "\",\"4\":-1}"}; }
cashflow_t RECEIVE(double x, const date_t& d, const currency_t& c) { return RECEIVE(CST(x), d, c); }
cashflow_t SET(const ticker_t& t, const amount_t& x) { return {"{\"0\":4,\"1\":\"" + t + "\",\"2\":" + x.s + "}"}; }
cashflow_t CASHFLOW(const path_t& p) { return {"{\"0\":5,\"1\":\"" + p + "\"}"}; }

IF::IF(const event_t& e, double l, double r) : e(e), l(l), r(r) {}
IF::IF(const event_t& e, double s) : e(e), l(s), r(s) {};
IF_EXERCISED::IF_EXERCISED(bool k, const date_t& d) : d(d), k(k) {}
IF_CALLED::IF_CALLED(const date_t& d) : IF_EXERCISED(true, d) {}
IF_PUTTED::IF_PUTTED(const date_t& d) : IF_EXERCISED(false, d) {}

amount_t IF::operator()(const amount_t& x, const amount_t& y) { return {"{\"0\":31,\"1\":" + e.s + ",\"2\":" + x.s + ",\"3\":" + y.s + ",\"4\":" + std::to_string(l) + ",\"5\":" + std::to_string(r) + "}"}; }
amount_t IF::operator()(double x, const amount_t& y) { return operator()(CST(x), y); }
amount_t IF::operator()(const amount_t& x, double y) { return operator()(x, CST(y)); }
amount_t IF::operator()(double x, double y) { return operator()(CST(x), CST(y)); }
amount_t IF::operator()(double x) { return operator()(CST(x), 0.); }
amount_t IF::operator()(const amount_t& x) { return operator()(x, 0.); }
cashflow_t IF::operator()(const cashflow_t& x, const cashflow_t& y) { return {"{\"0\":6,\"1\":" + e.s + ",\"2\":" + x.s + ",\"3\":" + y.s + ",\"4\":" + std::to_string(l) + ",\"5\":" + std::to_string(r) + "}"}; }
cashflow_t IF_EXERCISED::operator()(const cashflow_t& x, const cashflow_t& y) { return {"{\"0\":7,\"1\":" + std::to_string(k) + ",\"2\":\"" + d + "\",\"3\":" + x.s + ",\"4\":" + y.s + "}"}; }

int CONTRACT(
    const path_t& p,
    const cashflow_t& x
) {
    try {
        std::ofstream f;
        f.open(p);
        if(f.fail()) {
            return 1;
        }
        else {
            f << x.s;
            f.close();
            return 0;
        }
    }
    catch(const std::exception& e) {
        printf("%s", e);
        return 1;
    }
}