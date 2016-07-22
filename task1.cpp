#include<iostream>
#include<cassert>
using namespace std;
enum plan_type
{
    GLOD,
	SILVER
};


float calcMonthlyPhoneBill(plan_type type, int additionalLines)
{
    float glod_type_basic_monthly_rate = 49.95;
	float glod_type_per_additional_line_rate = 14.50;
	float silver_type_basic_monthly_rate = 29.95;
	float silver_type_per_additional_line_rate = 21.50;
	
	if (additionalLines < 1) 
		return 0.0;
    if(type == GLOD ) 
		return glod_type_basic_monthly_rate + (additionalLines - 1)*glod_type_per_additional_line_rate;
	if(type == SILVER ) 
		return silver_type_basic_monthly_rate + (additionalLines - 1)*silver_type_per_additional_line_rate;
	return 0.0;
}


void GiveGlodPlanTypeWithoutAdditionalLines()
{
    float basic_monthly_rate = 49.95;
    assert(basic_monthly_rate == calcMonthlyPhoneBill(GLOD,1));
}

void GiveGlodPlanTypeWithAdditionalLines()
{
    float basic_monthly_rate = 49.95;
	float per_additional_line_rate = 14.50;
	int additional_lines = 2;

	float expect_value = basic_monthly_rate + (additional_lines-1)*per_additional_line_rate;
    assert(expect_value == calcMonthlyPhoneBill(GLOD,additional_lines));

	additional_lines = 3;
	expect_value = basic_monthly_rate + (additional_lines-1)*per_additional_line_rate;
	assert(expect_value == calcMonthlyPhoneBill(GLOD,additional_lines));
}

void GiveSilverPlanTypeWithoutAdditionalLines()
{
    float basic_monthly_rate = 29.95;
    assert(basic_monthly_rate == calcMonthlyPhoneBill(SILVER,1));
}

void GiveSilverPlanTypeWithAdditionalLines()
{
    float basic_monthly_rate = 29.95;
	float per_additional_line_rate = 21.50;
	int additional_lines = 2;

	float expect_value = basic_monthly_rate + (additional_lines-1)*per_additional_line_rate;
    assert((basic_monthly_rate + (additional_lines-1)*per_additional_line_rate) == calcMonthlyPhoneBill(SILVER,additional_lines));

    additional_lines = 3;
	expect_value = basic_monthly_rate + (additional_lines-1)*per_additional_line_rate;	
	assert((basic_monthly_rate + (additional_lines-1)*per_additional_line_rate) == calcMonthlyPhoneBill(SILVER,additional_lines));
}


int main()
{
    
    GiveGlodPlanTypeWithoutAdditionalLines();
	GiveGlodPlanTypeWithAdditionalLines();
	GiveSilverPlanTypeWithoutAdditionalLines();
	GiveSilverPlanTypeWithAdditionalLines();
    return 0;
}

