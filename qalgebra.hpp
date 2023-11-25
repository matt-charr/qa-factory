/* ***************************************************************************************************** *
 * Copyright (C) 2023 Matthieu Charrier <matthieu.charrier.pro@gmail.com>. ***************************** *
 * All rights reserved. ******************************************************************************** *
 * This file is part of the project 'QA - Quantitative Analytics'. ************************************* *
 * Hence the latter remains the exclusive property of its author. ************************************** *
 * Accordingly, no part of this document may be used in any form for professional or commercial purposes *
 * without the express permission of Matthieu Charrier. ************************************************ *
 * ***************************************************************************************************** */

#ifndef _QALGEBRA_HEADER_INCLUDED
#define _QALGEBRA_HEADER_INCLUDED

#include <string>

#define THEN(insstruction) (insstruction,
#define ELSE(insstruction) insstruction)

namespace qalgebra {

   struct Event    { std::string s; };
   struct Amount   { std::string s; };
   struct CashFlow { std::string s; };

}

typedef std::string path_t;
typedef std::string ticker_t;
typedef std::string date_t;
typedef std::string date_shift_t;
typedef std::string currency_t;

typedef qalgebra::CashFlow cashflow_t;
typedef qalgebra::Amount amount_t;
typedef qalgebra::Event event_t;

amount_t operator+(const amount_t&);
amount_t operator+(const amount_t&, const amount_t&);
amount_t operator+(const amount_t&, double);
amount_t operator+(double, const amount_t&);
amount_t operator-(const amount_t&);
amount_t operator-(const amount_t&, const amount_t&);
amount_t operator-(const amount_t&, double);
amount_t operator-(double, const amount_t&);
amount_t operator*(const amount_t&, const amount_t&);
amount_t operator*(const amount_t&, double);
amount_t operator*(double, const amount_t&);
amount_t operator/(const amount_t&, const amount_t&);
amount_t operator/(const amount_t&, double);
amount_t operator/(double, const amount_t&);
event_t operator<=(const amount_t&, const amount_t&);
event_t operator<=(const amount_t&, double);
event_t operator<=(double, const amount_t&);
event_t operator<(const amount_t&, const amount_t&);
event_t operator<(const amount_t&, double);
event_t operator<(double, const amount_t&);
event_t operator>=(const amount_t&, const amount_t&);
event_t operator>=(const amount_t&, double);
event_t operator>=(double, const amount_t&);
event_t operator>(const amount_t&, const amount_t&);
event_t operator>(const amount_t&, double);
event_t operator>(double, const amount_t&);
event_t operator==(const amount_t&, const amount_t&);
event_t operator==(const amount_t&, double);
event_t operator==(double, const amount_t&);
event_t operator!=(const amount_t&, const amount_t&);
event_t operator!=(const amount_t&, double);
event_t operator!=(double, const amount_t&);
event_t operator&&(const event_t&, const event_t&);
event_t operator||(const event_t&, const event_t&);
event_t operator!(const event_t&);
cashflow_t operator&(const cashflow_t&, const cashflow_t&);

amount_t SPOT(const ticker_t&, const date_t&, const date_shift_t& = "");
amount_t SPOT_COMPOSITE(const ticker_t&, const date_t&, const currency_t&, const date_shift_t& = "");
amount_t REF(const std::string&, double);
amount_t CST(double);
amount_t AMOUNT(const ticker_t&);
amount_t POW(const amount_t&, unsigned);
amount_t ABS(const amount_t&);
amount_t COS(const amount_t&);
amount_t MIN(const amount_t&);
amount_t TAN(const amount_t&);
amount_t EXP(const amount_t&);
amount_t LOG(const amount_t&);
amount_t SQRT(const amount_t&);
amount_t MAX(const amount_t&, const amount_t&);
amount_t MAX(const amount_t&, double);
amount_t MAX(double, const amount_t&);
amount_t MIN(const amount_t&, const amount_t&);
amount_t MIN(const amount_t&, double);
amount_t MIN(double, const amount_t&);
event_t CST(bool);
cashflow_t BUY(const date_t&, double, const cashflow_t&);
cashflow_t BUY(const date_t&, const cashflow_t&);
cashflow_t SELL(const date_t&, const double, const cashflow_t&);
cashflow_t SELL(const date_t&, const cashflow_t&);
cashflow_t END(void);
cashflow_t PAY(const amount_t&, const date_t&, const currency_t&);
cashflow_t PAY(const double, const date_t&, const currency_t&);
cashflow_t RECEIVE(const amount_t&, const date_t&, const currency_t&);
cashflow_t RECEIVE(double, const date_t&, const currency_t&);
cashflow_t SET(const ticker_t&, const amount_t&);
cashflow_t CASHFLOW(const path_t&);

struct IF {
    event_t e; double l; double r;
    IF(const event_t&, double = 0., double = 0.);
    IF(const event_t&, double);
    amount_t operator()(const amount_t&, const amount_t&);
    amount_t operator()(double, const amount_t&);
    amount_t operator()(const amount_t&, double);
    amount_t operator()(double, double);
    amount_t operator()(double);
    amount_t operator()(const amount_t&);
    cashflow_t operator()(const cashflow_t&, const cashflow_t&);
};

struct IF_EXERCISED {
    date_t d; bool k;
    IF_EXERCISED(bool, const date_t&);
    cashflow_t operator()(const cashflow_t&, const cashflow_t&);
};

struct IF_CALLED : public IF_EXERCISED { 
    IF_CALLED(const date_t&);
};

struct IF_PUTTED : public IF_EXERCISED { 
    IF_PUTTED(const date_t&);
};

int CONTRACT(const path_t&, const cashflow_t&);

#endif