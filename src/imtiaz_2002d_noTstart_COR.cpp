//! @file
//!
//! This source file was generated from CellML.
//!
//! Model: imtiaz_2002
//!
//! Processed by pycml - CellML Tools in Python
//!     (translators: , pycml: , optimize: )
//! on Tue Jul 20 14:34:44 2021
//!
//! <autogenerated>

#include "imtiaz_2002d_noTstart_COR.hpp"
#include <cmath>
#include <cassert>
#include <memory>
#include "Exception.hpp"
#include "OdeSystemInformation.hpp"
#include "RegularStimulus.hpp"
#include "HeartConfig.hpp"
#include "IsNan.hpp"
#include "MathsCustomFunctions.hpp"

    Cellimtiaz_2002d_noTstart_CORFromCellML::Cellimtiaz_2002d_noTstart_CORFromCellML(boost::shared_ptr<AbstractIvpOdeSolver> pSolver, boost::shared_ptr<AbstractStimulusFunction> pIntracellularStimulus)
        : AbstractCardiacCell(
                pSolver,
                7,
                0,
                pIntracellularStimulus)
    {
        // Time units: millisecond
        //
        this->mpSystemInfo = OdeSystemInformation<Cellimtiaz_2002d_noTstart_CORFromCellML>::Instance();
        Init();
    }

    Cellimtiaz_2002d_noTstart_CORFromCellML::~Cellimtiaz_2002d_noTstart_CORFromCellML()
    {
    }

    double Cellimtiaz_2002d_noTstart_CORFromCellML::GetIIonic(const std::vector<double>* pStateVariables)
    {
        // For state variable interpolation (SVI) we read in interpolated state variables,
        // otherwise for ionic current interpolation (ICI) we use the state variables of this model (node).
        if (!pStateVariables) pStateVariables = &rGetStateVariables();
        const std::vector<double>& rY = *pStateVariables;
        double var_chaste_interface__Membrane__V_m = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -70.5156
        double var_chaste_interface__d_Na__d_Na = rY[1];
        // Units: dimensionless; Initial value: 0
        double var_chaste_interface__f_Na__f_Na = rY[2];
        // Units: dimensionless; Initial value: 0.9997
        double var_chaste_interface__intracellular_Ca__Ca_c = rY[3];
        // Units: millimolar; Initial value: 0.2886

        const double var_Membrane__V_m = var_chaste_interface__Membrane__V_m; // voltage_units
        const double var_Membrane__C_m = 26.0; // capacitance_units
        const double var_i_Na__E_Na = 80.0; // voltage_units
        const double var_Membrane__f_Na = var_chaste_interface__f_Na__f_Na; // dimensionless
        const double var_i_Na__f_Na = var_Membrane__f_Na; // dimensionless
        const double var_Membrane__d_Na = var_chaste_interface__d_Na__d_Na; // dimensionless
        const double var_i_Na__d_Na = var_Membrane__d_Na; // dimensionless
        const double var_i_Na__V_m = var_Membrane__V_m; // voltage_units
        const double var_i_Na__G_Na = 28.0; // conductance_units
        const double var_i_Na__I_Na = var_i_Na__G_Na * var_i_Na__f_Na * var_i_Na__d_Na * (var_i_Na__V_m - var_i_Na__E_Na); // current_units
        const double var_Membrane__Ca_c = var_chaste_interface__intracellular_Ca__Ca_c; // millimolar
        const double var_i_Ca__Ca_c = var_Membrane__Ca_c; // millimolar
        const double var_i_Ca__q = 4.0; // dimensionless
        const double var_i_Ca__G_MCa = 4.0; // conductance_units
        const double var_i_Ca__k_Ca = 0.93999999999999995; // millimolar
        const double var_i_Ca__G_Ca = (var_i_Ca__G_MCa * pow(var_i_Ca__Ca_c, var_i_Ca__q)) / (pow(var_i_Ca__k_Ca, var_i_Ca__q) + pow(var_i_Ca__Ca_c, var_i_Ca__q)); // conductance_units
        const double var_i_Ca__E_Ca =  -20.0; // voltage_units
        const double var_i_Ca__V_m = var_Membrane__V_m; // voltage_units
        const double var_i_Ca__I_Ca = var_i_Ca__G_Ca * (var_i_Ca__V_m - var_i_Ca__E_Ca); // current_units
        const double var_i_BK__V_m = var_Membrane__V_m; // voltage_units
        const double var_i_BK__G_max_BK = 1.2; // conductance_units
        const double var_i_BK__Ca_c = var_Membrane__Ca_c; // millimolar
        const double var_d_BK__Ca_c = var_i_BK__Ca_c; // millimolar
        const double var_d_BK__V_m = var_i_BK__V_m; // voltage_units
        const double var_d_BK__d_BK = 1.0 / (1.0 + exp((var_d_BK__V_m / (-17.0)) - (2.0 * log(var_d_BK__Ca_c / 0.001)))); // dimensionless
        const double var_i_BK__d_BK = var_d_BK__d_BK; // dimensionless
        const double var_i_BK__E_K =  -72.0; // voltage_units
        const double var_i_BK__I_BK = var_i_BK__G_max_BK * var_i_BK__d_BK * (var_i_BK__V_m - var_i_BK__E_K); // current_units
        const double var_Membrane__I_stim = 0.0; // current_units
        const double var_Membrane__i_Na__I_Na = var_i_Na__I_Na; // current_units
        const double var_Membrane__i_Ca__I_Ca = var_i_Ca__I_Ca; // current_units
        const double var_Membrane__i_BK__I_BK = var_i_BK__I_BK; // current_units
        const double var_chaste_interface__i_Na__I_Na = var_Membrane__i_Na__I_Na; // current_units
        const double var_chaste_interface__i_Ca__I_Ca = var_Membrane__i_Ca__I_Ca; // current_units
        const double var_chaste_interface__Membrane__C_m = var_Membrane__C_m; // capacitance_units
        const double var_chaste_interface__i_BK__I_BK = var_Membrane__i_BK__I_BK; // current_units
        const double var_chaste_interface__Membrane__I_stim = var_Membrane__I_stim; // current_units
        const double var_chaste_interface__i_ionic = ((var_chaste_interface__i_Na__I_Na + var_chaste_interface__i_Ca__I_Ca + var_chaste_interface__i_BK__I_BK + var_chaste_interface__Membrane__I_stim) / var_chaste_interface__Membrane__C_m) * HeartConfig::Instance()->GetCapacitance(); // uA_per_cm2

        const double i_ionic = var_chaste_interface__i_ionic;
        EXCEPT_IF_NOT(!std::isnan(i_ionic));
        return i_ionic;
    }

    void Cellimtiaz_2002d_noTstart_CORFromCellML::EvaluateYDerivatives(double var_chaste_interface__Time__time, const std::vector<double>& rY, std::vector<double>& rDY)
    {
        // Inputs:
        // Time units: millisecond
        double var_chaste_interface__Membrane__V_m = (mSetVoltageDerivativeToZero ? this->mFixedVoltage : rY[0]);
        // Units: millivolt; Initial value: -70.5156
        double var_chaste_interface__d_Na__d_Na = rY[1];
        // Units: dimensionless; Initial value: 0
        double var_chaste_interface__f_Na__f_Na = rY[2];
        // Units: dimensionless; Initial value: 0.9997
        double var_chaste_interface__intracellular_Ca__Ca_c = rY[3];
        // Units: millimolar; Initial value: 0.2886
        double var_chaste_interface__intracellular_Ca__Ca_s = rY[4];
        // Units: millimolar; Initial value: 2.0014
        double var_chaste_interface__intracellular_Ca__IP_3 = rY[5];
        // Units: millimolar; Initial value: 0.3791

        // Mathematics
        double d_dt_chaste_interface__Membrane__V_m;
        const double var_Membrane__V_m = var_chaste_interface__Membrane__V_m; // voltage_units
        const double var_Membrane__f_Na = var_chaste_interface__f_Na__f_Na; // dimensionless
        const double var_i_Na__f_Na = var_Membrane__f_Na; // dimensionless
        const double var_Membrane__d_Na = var_chaste_interface__d_Na__d_Na; // dimensionless
        const double var_i_Na__d_Na = var_Membrane__d_Na; // dimensionless
        const double var_i_Na__V_m = var_Membrane__V_m; // voltage_units
        const double var_Membrane__Ca_c = var_chaste_interface__intracellular_Ca__Ca_c; // millimolar
        const double var_Membrane__Cor = 1.0; // dimensionless
        const double var_d_Na__V_m = var_i_Na__V_m; // voltage_units
        const double var_d_Na__d_inf_Na = 1.0 / (1.0 + exp((var_d_Na__V_m + 7.0) / (-5.0))); // dimensionless
        const double var_d_Na__d_Na = var_i_Na__d_Na; // dimensionless
        const double var_d_Na__tau_d_Na = 10.26; // time_units
        const double var_i_Na__Cor = var_Membrane__Cor; // dimensionless
        const double var_d_Na__Cor = var_i_Na__Cor; // dimensionless
        const double var_d_Na__d_d_Na_d_Time__time = (var_d_Na__Cor * (var_d_Na__d_inf_Na - var_d_Na__d_Na)) / var_d_Na__tau_d_Na; // 'per millisecond'
        const double var_i_Na__d_Na__d_d_Na_d_Time__time = var_d_Na__d_d_Na_d_Time__time; // ___units_7
        const double var_Membrane__d_Na__d_d_Na_d_Time__time = var_i_Na__d_Na__d_d_Na_d_Time__time; // ___units_7
        const double var_f_Na__V_m = var_i_Na__V_m; // voltage_units
        const double var_f_Na__f_inf_Na = 1.0 / (1.0 + exp((var_f_Na__V_m + 37.399999999999999) / 4.0)); // dimensionless
        const double var_f_Na__f_Na = var_i_Na__f_Na; // dimensionless
        const double var_f_Na__Cor = var_i_Na__Cor; // dimensionless
        const double var_f_Na__tau_f_Na = 112.81999999999999; // time_units
        const double var_f_Na__d_f_Na_d_Time__time = (var_f_Na__Cor * (var_f_Na__f_inf_Na - var_f_Na__f_Na)) / var_f_Na__tau_f_Na; // 'per millisecond'
        const double var_i_Na__f_Na__d_f_Na_d_Time__time = var_f_Na__d_f_Na_d_Time__time; // ___units_7
        const double var_Membrane__f_Na__d_f_Na_d_Time__time = var_i_Na__f_Na__d_f_Na_d_Time__time; // ___units_7
        const double var_intracellular_Ca__Ca_c = var_Membrane__Ca_c; // millimolar
        const double var_Membrane__IP_3 = var_chaste_interface__intracellular_Ca__IP_3; // millimolar
        const double var_intracellular_Ca__IP_3 = var_Membrane__IP_3; // millimolar
        const double var_intracellular_Ca__V_1 = 0.00022094000000000001; // per_time_units
        const double var_intracellular_Ca__V_0 = 0.00021450000000000001; // millimolar_per_time_units
        const double var_intracellular_Ca__V_in = var_intracellular_Ca__V_0 + (var_intracellular_Ca__V_1 * var_intracellular_Ca__IP_3); // millimolar_per_time_units
        const double var_intracellular_Ca__k_f = 5.8499999999999999e-05; // per_time_units
        const double var_intracellular_Ca__Cor = var_Membrane__Cor; // dimensionless
        const double var_intracellular_Ca__w = 4.0; // dimensionless
        const double var_intracellular_Ca__k_a = 0.90000000000000002; // millimolar
        const double var_intracellular_Ca__V_M3 = 0.32240000000000002; // millimolar_per_time_units
        const double var_Membrane__Ca_s = var_chaste_interface__intracellular_Ca__Ca_s; // millimolar
        const double var_intracellular_Ca__Ca_s = var_Membrane__Ca_s; // millimolar
        const double var_intracellular_Ca__k_r = 2.0; // millimolar
        const double var_intracellular_Ca__o = 4.0; // dimensionless
        const double var_intracellular_Ca__k_p = 0.65000000000000002; // millimolar
        const double var_intracellular_Ca__m = 4.0; // dimensionless
        const double var_intracellular_Ca__V_3 = (((((var_intracellular_Ca__V_M3 * pow(var_intracellular_Ca__Ca_c, var_intracellular_Ca__w)) / (pow(var_intracellular_Ca__k_a, var_intracellular_Ca__w) + pow(var_intracellular_Ca__Ca_c, var_intracellular_Ca__w))) * pow(var_intracellular_Ca__Ca_s, var_intracellular_Ca__m)) / (pow(var_intracellular_Ca__k_r, var_intracellular_Ca__m) + pow(var_intracellular_Ca__Ca_s, var_intracellular_Ca__m))) * pow(var_intracellular_Ca__IP_3, var_intracellular_Ca__o)) / (pow(var_intracellular_Ca__k_p, var_intracellular_Ca__o) + pow(var_intracellular_Ca__IP_3, var_intracellular_Ca__o)); // millimolar_per_time_units
        const double var_intracellular_Ca__k_2 = 1.0; // millimolar
        const double var_intracellular_Ca__n = 2.0; // dimensionless
        const double var_intracellular_Ca__V_M2 = 0.0048999999999999998; // millimolar_per_time_units
        const double var_intracellular_Ca__V_2 = (var_intracellular_Ca__V_M2 * pow(var_intracellular_Ca__Ca_c, var_intracellular_Ca__n)) / (pow(var_intracellular_Ca__k_2, var_intracellular_Ca__n) + pow(var_intracellular_Ca__Ca_c, var_intracellular_Ca__n)); // millimolar_per_time_units
        const double var_intracellular_Ca__K = 0.00064349999999999997; // per_time_units
        const double var_intracellular_Ca__d_Ca_c_d_Time__time = var_intracellular_Ca__Cor * (((var_intracellular_Ca__V_in - var_intracellular_Ca__V_2) + var_intracellular_Ca__V_3 + (var_intracellular_Ca__k_f * var_intracellular_Ca__Ca_s)) - (var_intracellular_Ca__K * var_intracellular_Ca__Ca_c)); // 'millimole per litre per millisecond'
        const double var_Membrane__intracellular_Ca__d_Ca_c_d_Time__time = var_intracellular_Ca__d_Ca_c_d_Time__time; // ___units_21
        const double var_intracellular_Ca__d_Ca_s_d_Time__time = var_intracellular_Ca__Cor * ((var_intracellular_Ca__V_2 - var_intracellular_Ca__V_3) - (var_intracellular_Ca__k_f * var_intracellular_Ca__Ca_s)); // 'millimole per litre per millisecond'
        const double var_Membrane__intracellular_Ca__d_Ca_s_d_Time__time = var_intracellular_Ca__d_Ca_s_d_Time__time; // ___units_21
        const double var_intracellular_Ca__u = 4.0; // dimensionless
        const double var_intracellular_Ca__r = 8.0; // dimensionless
        const double var_intracellular_Ca__P_MV = 0.032500000000000001; // millimolar_per_time_units
        const double var_intracellular_Ca__eta = mParameters[0]; // per_time_units
        //const double var_intracellular_Ca__eta = rY[6]; // per_time_units
        const double var_intracellular_Ca__V_m = var_Membrane__V_m; // voltage_units
        const double var_intracellular_Ca__beta = 0.00097499999999999996; // millimolar_per_time_units
        const double var_intracellular_Ca__k_v =  -68.0; // voltage_units
        const double var_intracellular_Ca__k_4 = 0.5; // millimolar
        const double var_intracellular_Ca__V_M4 = 0.00048749999999999998; // millimolar_per_time_units
        const double var_intracellular_Ca__d_IP_3_d_Time__time = var_intracellular_Ca__Cor * (((var_intracellular_Ca__beta - (var_intracellular_Ca__eta * var_intracellular_Ca__IP_3)) - ((var_intracellular_Ca__V_M4 * pow(var_intracellular_Ca__IP_3, var_intracellular_Ca__u)) / (pow(var_intracellular_Ca__k_4, var_intracellular_Ca__u) + pow(var_intracellular_Ca__IP_3, var_intracellular_Ca__u)))) + (var_intracellular_Ca__P_MV * (1.0 - (pow(var_intracellular_Ca__V_m, var_intracellular_Ca__r) / (pow(var_intracellular_Ca__k_v, var_intracellular_Ca__r) + pow(var_intracellular_Ca__V_m, var_intracellular_Ca__r)))))); // 'millimole per litre per millisecond'
        const double var_Membrane__intracellular_Ca__d_IP_3_d_Time__time = var_intracellular_Ca__d_IP_3_d_Time__time; // ___units_21
        const double var_chaste_interface__d_Na__d_d_Na_d_Time__time = var_Membrane__d_Na__d_d_Na_d_Time__time; // ___units_7
        const double var_chaste_interface__f_Na__d_f_Na_d_Time__time = var_Membrane__f_Na__d_f_Na_d_Time__time; // ___units_7
        const double var_chaste_interface__intracellular_Ca__d_Ca_c_d_Time__time = var_Membrane__intracellular_Ca__d_Ca_c_d_Time__time; // ___units_29
        const double var_chaste_interface__intracellular_Ca__d_Ca_s_d_Time__time = var_Membrane__intracellular_Ca__d_Ca_s_d_Time__time; // ___units_29
        const double var_chaste_interface__intracellular_Ca__d_IP_3_d_Time__time = var_Membrane__intracellular_Ca__d_IP_3_d_Time__time; // ___units_29
        const double d_dt_chaste_interface__d_Na__d_Na = var_chaste_interface__d_Na__d_d_Na_d_Time__time; // 'per millisecond'
        const double d_dt_chaste_interface__f_Na__f_Na = var_chaste_interface__f_Na__d_f_Na_d_Time__time; // 'per millisecond'
        const double d_dt_chaste_interface__intracellular_Ca__Ca_c = var_chaste_interface__intracellular_Ca__d_Ca_c_d_Time__time; // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__intracellular_Ca__Ca_s = var_chaste_interface__intracellular_Ca__d_Ca_s_d_Time__time; // 'millimole per litre per millisecond'
        const double d_dt_chaste_interface__intracellular_Ca__IP_3 = var_chaste_interface__intracellular_Ca__d_IP_3_d_Time__time; // 'millimole per litre per millisecond'
        //std::cout << var_intracellular_Ca__eta << "\n";
        if (mSetVoltageDerivativeToZero)
        {
            d_dt_chaste_interface__Membrane__V_m = 0.0;
        }
        else
        {
            const double var_Membrane__C_m = 26.0; // capacitance_units
            const double var_i_Na__E_Na = 80.0; // voltage_units
            const double var_i_Na__G_Na = 28.0; // conductance_units
            const double var_i_Na__I_Na = var_i_Na__G_Na * var_i_Na__f_Na * var_i_Na__d_Na * (var_i_Na__V_m - var_i_Na__E_Na); // current_units
            const double var_Membrane__I_Na = var_i_Na__I_Na; // current_units
            const double var_i_Ca__Ca_c = var_Membrane__Ca_c; // millimolar
            const double var_i_Ca__q = 4.0; // dimensionless
            const double var_i_Ca__G_MCa = 4.0; // conductance_units
            const double var_i_Ca__k_Ca = 0.93999999999999995; // millimolar
            const double var_i_Ca__G_Ca = (var_i_Ca__G_MCa * pow(var_i_Ca__Ca_c, var_i_Ca__q)) / (pow(var_i_Ca__k_Ca, var_i_Ca__q) + pow(var_i_Ca__Ca_c, var_i_Ca__q)); // conductance_units
            const double var_i_Ca__E_Ca =  -20.0; // voltage_units
            const double var_i_Ca__V_m = var_Membrane__V_m; // voltage_units
            const double var_i_Ca__I_Ca = var_i_Ca__G_Ca * (var_i_Ca__V_m - var_i_Ca__E_Ca); // current_units
            const double var_Membrane__I_Ca = var_i_Ca__I_Ca; // current_units
            const double var_i_BK__V_m = var_Membrane__V_m; // voltage_units
            const double var_i_BK__G_max_BK = 1.2; // conductance_units
            const double var_i_BK__Ca_c = var_Membrane__Ca_c; // millimolar
            const double var_d_BK__Ca_c = var_i_BK__Ca_c; // millimolar
            const double var_d_BK__V_m = var_i_BK__V_m; // voltage_units
            const double var_d_BK__d_BK = 1.0 / (1.0 + exp((var_d_BK__V_m / (-17.0)) - (2.0 * log(var_d_BK__Ca_c / 0.001)))); // dimensionless
            const double var_i_BK__d_BK = var_d_BK__d_BK; // dimensionless
            const double var_i_BK__E_K =  -72.0; // voltage_units
            const double var_i_BK__I_BK = var_i_BK__G_max_BK * var_i_BK__d_BK * (var_i_BK__V_m - var_i_BK__E_K); // current_units
            const double var_Membrane__I_BK = var_i_BK__I_BK; // current_units
            const double var_Membrane__I_stim = 0.0; // current_units
            const double var_Membrane__d_V_m_d_Time__time = ((-var_Membrane__Cor) * ((var_Membrane__I_Na + var_Membrane__I_Ca + var_Membrane__I_BK) - var_Membrane__I_stim)) / var_Membrane__C_m; // 'millivolt per millisecond'
            const double var_chaste_interface__Membrane__d_V_m_d_Time__time = var_Membrane__d_V_m_d_Time__time; // ___units_1
            d_dt_chaste_interface__Membrane__V_m = var_chaste_interface__Membrane__d_V_m_d_Time__time; // 'millivolt per millisecond'
        }

        rDY[0] = d_dt_chaste_interface__Membrane__V_m;
        rDY[1] = d_dt_chaste_interface__d_Na__d_Na;
        rDY[2] = d_dt_chaste_interface__f_Na__f_Na;
        rDY[3] = d_dt_chaste_interface__intracellular_Ca__Ca_c;
        rDY[4] = d_dt_chaste_interface__intracellular_Ca__Ca_s;
        rDY[5] = d_dt_chaste_interface__intracellular_Ca__IP_3;
    }

template<>
void OdeSystemInformation<Cellimtiaz_2002d_noTstart_CORFromCellML>::Initialise(void)
{
    this->mSystemName = "imtiaz_2002";
    this->mFreeVariableName = "Time__time";
    this->mFreeVariableUnits = "millisecond";

    // rY[0]:
    this->mVariableNames.push_back("Membrane__V_m");
    this->mVariableUnits.push_back("millivolt");
    this->mInitialConditions.push_back(-70.5156);

    // rY[1]:
    this->mVariableNames.push_back("d_Na__d_Na");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0);

    // rY[2]:
    this->mVariableNames.push_back("f_Na__f_Na");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.9997);

    // rY[3]:
    this->mVariableNames.push_back("intracellular_Ca__Ca_c");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.2886);

    // rY[4]:
    this->mVariableNames.push_back("intracellular_Ca__Ca_s");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(2.0014);

    // rY[5]:
    this->mVariableNames.push_back("intracellular_Ca__IP_3");
    this->mVariableUnits.push_back("millimolar");
    this->mInitialConditions.push_back(0.3791);

    /////////////////// Added R. Avci ///////////////////////
    // rY[6]: a new state variable (currently not used)
    this->mVariableNames.push_back("eta");
    this->mVariableUnits.push_back("dimensionless");
    this->mInitialConditions.push_back(0.045);
    // mParameters[0]: a new parameter that should be set for each cell
    this->mParameterNames.push_back("eta");
    this->mParameterUnits.push_back("dimensionless");

    this->mInitialised = true;
}

// Serialization for Boost >= 1.36
#include "SerializationExportWrapperForCpp.hpp"
CHASTE_CLASS_EXPORT(Cellimtiaz_2002d_noTstart_CORFromCellML)
