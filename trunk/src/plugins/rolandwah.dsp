// generated automatically
// DO NOT MODIFY!
declare id "rolandwah";
declare name "Roland Double Beat";
declare category "Guitar Effects";
declare shortname "Double Beat";
declare description "Roland Double Beat";

import("filter.lib");
import("effect.lib");
import("oscillator.lib");

    LogPot(a, x) = if(a, (exp(a * x) - 1) / (exp(a) - 1), x);
    Inverted(b, x) = if(b, 1 - x, x);
    s = 0.993;
    fs = float(SR);

    wet = vslider("wet_dry[name:wet/dry][tooltip:percentage of processed signal in output signal]",  100, 0, 100, 1) : /(100);
    dry = 1 - wet;
    gain = vslider("Gain[name:Gain][tooltip:Gain of the Fuzz Section (dB)]", -12, -40, 4, 0.1) : db2linear : smooth(s);

fuzz = iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0,b6/a0,b7/a0,b8/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0,a6/a0,a7/a0,a8/a0)) with {


    Fuzz = vslider("Fuzz[name:Fuzz]", 0.5, 0, 1, 0.01) : Inverted(0) : LogPot(0) : smooth(s);
    
    
    b0 = Fuzz*pow(fs,4)*(fs*(fs*(8.60349117319693e-33*fs + 7.42470650533226e-26) + 3.80828462584721e-23) + 8.28085042193987e-22) + pow(fs,3)*(fs*(fs*(fs*(-2.62267793598193e-32*fs - 2.30252524666021e-25) - 1.21809214941527e-22) - 4.47006878788668e-21) - 4.14042521096994e-20);

    b1 = Fuzz*pow(fs,5)*(fs*(-5.16209470391816e-32*fs - 2.9698826021329e-25) - 7.61656925169443e-23) + pow(fs,3)*(pow(fs,2)*(fs*(1.57360676158916e-31*fs + 9.21010098664083e-25) + 2.43618429883054e-22) - 8.28085042193987e-20);

    b2 = Fuzz*pow(fs,4)*(fs*(fs*(1.20448876424757e-31*fs + 2.9698826021329e-25) - 7.61656925169443e-23) - 3.31234016877595e-21) + pow(fs,3)*(fs*(fs*(fs*(-3.6717491103747e-31*fs - 9.21010098664083e-25) + 2.43618429883054e-22) + 1.78802751515467e-20) + 8.28085042193987e-20);

    b3 = Fuzz*pow(fs,5)*(fs*(-1.20448876424757e-31*fs + 2.9698826021329e-25) + 2.28497077550833e-22) + pow(fs,3)*(pow(fs,2)*(fs*(3.6717491103747e-31*fs - 9.21010098664083e-25) - 7.30855289649162e-22) + 2.48425512658196e-19);

    b4 = Fuzz*pow(fs,4)*(-7.42470650533226e-25*pow(fs,2) + 4.96851025316392e-21) + pow(fs,4)*(2.30252524666021e-24*pow(fs,2) - 2.68204127273201e-20);

    b5 = Fuzz*pow(fs,5)*(fs*(1.20448876424757e-31*fs + 2.9698826021329e-25) - 2.28497077550833e-22) + pow(fs,3)*(pow(fs,2)*(fs*(-3.6717491103747e-31*fs - 9.21010098664083e-25) + 7.30855289649162e-22) - 2.48425512658196e-19);

    b6 = Fuzz*pow(fs,4)*(fs*(fs*(-1.20448876424757e-31*fs + 2.9698826021329e-25) + 7.61656925169443e-23) - 3.31234016877595e-21) + pow(fs,3)*(fs*(fs*(fs*(3.6717491103747e-31*fs - 9.21010098664083e-25) - 2.43618429883054e-22) + 1.78802751515467e-20) - 8.28085042193987e-20);

    b7 = Fuzz*pow(fs,5)*(fs*(5.16209470391816e-32*fs - 2.9698826021329e-25) + 7.61656925169443e-23) + pow(fs,3)*(pow(fs,2)*(fs*(-1.57360676158916e-31*fs + 9.21010098664083e-25) - 2.43618429883054e-22) + 8.28085042193987e-20);

    b8 = Fuzz*pow(fs,4)*(fs*(fs*(-8.60349117319693e-33*fs + 7.42470650533226e-26) - 3.80828462584721e-23) + 8.28085042193987e-22) + pow(fs,3)*(fs*(fs*(fs*(2.62267793598193e-32*fs - 2.30252524666021e-25) + 1.21809214941527e-22) - 4.47006878788668e-21) + 4.14042521096994e-20);

    a0 = Fuzz*fs*(fs*(fs*(fs*(fs*(fs*(fs*(9.64198439050231e-55*fs - 5.76952472985784e-34) - 1.84629565839962e-29) - 5.28116058056682e-26) - 3.4488417342687e-23) - 6.7753494863719e-21) - 1.6046797673707e-19) - 6.03074438986166e-19) + fs*(fs*(fs*(fs*(fs*(fs*(fs*(-1.08067210692624e-54*fs + 1.6917880698614e-33) + 2.29812823706864e-29) + 5.73340871630524e-26) + 3.80795187898005e-23) + 8.56555972538848e-21) + 5.00114968075696e-19) + 8.62923424920947e-18) + 3.01537219493083e-17;

    a1 = Fuzz*fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(-7.71358751240185e-54*fs + 3.46171483791471e-33) + 7.38518263359847e-29) + 1.05623211611336e-25) - 1.35506989727438e-20) - 6.41871906948282e-19) - 3.618446633917e-18) + fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(8.64537685540996e-54*fs - 1.01507284191684e-32) - 9.19251294827458e-29) - 1.14668174326105e-25) + 1.7131119450777e-20) + 2.00045987230279e-18) + 5.17754054952568e-17) + 2.41229775594467e-16;

    a2 = Fuzz*fs*(fs*(fs*(fs*(fs*(fs*(fs*(2.69975562934065e-53*fs - 8.07733462180098e-33) - 7.38518263359847e-29) + 1.05623211611336e-25) + 1.37953669370748e-22) + 1.35506989727438e-20) - 6.41871906948282e-19) - 8.44304214580633e-18) + fs*(fs*(fs*(fs*(fs*(fs*(fs*(-3.02588189939348e-53*fs + 2.36850329780596e-32) + 9.19251294827458e-29) - 1.14668174326105e-25) - 1.52318075159202e-22) - 1.7131119450777e-20) + 2.00045987230279e-18) + 1.20809279488933e-16) + 8.44304214580633e-16;

    a3 = Fuzz*fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(-5.3995112586813e-53*fs + 8.07733462180098e-33) - 7.38518263359847e-29) - 3.16869634834009e-25) + 4.06520969182314e-20) + 6.41871906948282e-19) - 8.44304214580633e-18) + fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(6.05176379878697e-53*fs - 2.36850329780596e-32) + 9.19251294827458e-29) + 3.44004522978315e-25) - 5.13933583523309e-20) - 2.00045987230279e-18) + 1.20809279488933e-16) + 1.68860842916127e-15;

    a4 = Fuzz*pow(fs,2)*(pow(fs,2)*(pow(fs,2)*(6.74938907335162e-53*pow(fs,2) + 1.84629565839962e-28) - 2.06930504056122e-22) + 1.6046797673707e-18) + pow(fs,2)*(pow(fs,2)*(pow(fs,2)*(-7.56470474848371e-53*pow(fs,2) - 2.29812823706864e-28) + 2.28477112738803e-22) - 5.00114968075697e-18) + 2.11076053645158e-15;

    a5 = Fuzz*fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(-5.3995112586813e-53*fs - 8.07733462180098e-33) - 7.38518263359847e-29) + 3.16869634834009e-25) - 4.06520969182314e-20) + 6.41871906948282e-19) + 8.44304214580633e-18) + fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(6.05176379878697e-53*fs + 2.36850329780596e-32) + 9.19251294827458e-29) - 3.44004522978315e-25) + 5.13933583523309e-20) - 2.00045987230279e-18) - 1.20809279488933e-16) + 1.68860842916127e-15;

    a6 = Fuzz*fs*(fs*(fs*(fs*(fs*(fs*(fs*(2.69975562934065e-53*fs + 8.07733462180098e-33) - 7.38518263359847e-29) - 1.05623211611336e-25) + 1.37953669370748e-22) - 1.35506989727438e-20) - 6.41871906948282e-19) + 8.44304214580633e-18) + fs*(fs*(fs*(fs*(fs*(fs*(fs*(-3.02588189939348e-53*fs - 2.36850329780596e-32) + 9.19251294827458e-29) + 1.14668174326105e-25) - 1.52318075159202e-22) + 1.7131119450777e-20) + 2.00045987230279e-18) - 1.20809279488933e-16) + 8.44304214580633e-16;

    a7 = Fuzz*fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(-7.71358751240185e-54*fs - 3.46171483791471e-33) + 7.38518263359847e-29) - 1.05623211611336e-25) + 1.35506989727438e-20) - 6.41871906948282e-19) + 3.618446633917e-18) + fs*(fs*(fs*(pow(fs,2)*(fs*(fs*(8.64537685540996e-54*fs + 1.01507284191684e-32) - 9.19251294827458e-29) + 1.14668174326105e-25) - 1.7131119450777e-20) + 2.00045987230279e-18) - 5.17754054952568e-17) + 2.41229775594467e-16;

    a8 = Fuzz*fs*(fs*(fs*(fs*(fs*(fs*(fs*(9.64198439050231e-55*fs + 5.76952472985784e-34) - 1.84629565839962e-29) + 5.28116058056682e-26) - 3.4488417342687e-23) + 6.7753494863719e-21) - 1.6046797673707e-19) + 6.03074438986166e-19) + fs*(fs*(fs*(fs*(fs*(fs*(fs*(-1.08067210692624e-54*fs - 1.6917880698614e-33) + 2.29812823706864e-29) - 5.73340871630524e-26) + 3.80795187898005e-23) - 8.56555972538848e-21) + 5.00114968075696e-19) - 8.62923424920947e-18) + 3.01537219493083e-17;
};

wah(x) = x : iir((b0/a0,b1/a0,b2/a0,b3/a0,b4/a0,b5/a0,b6/a0),(a1/a0,a2/a0,a3/a0,a4/a0,a5/a0,a6/a0)) with {

    Wah1 = (x : amp_follower_ud(0.01,0.1) : min(0.9) : max(0.09) );
    
    Wah2 = vslider("Wah[name:Wah]", 0.5, 0.02, 1, 0.01) : Inverted(1) : LogPot(1) : smooth(s);
    
    sl = checkbox("mode[enum:manual|auto|alien]");

    Wah3 = (oscs(freq) + 1) / 2 : min(0.9) : max(0.09) : Inverted(1) with {
        freq = vslider("lfobpm[name:Alien Freq][tooltip:LFO in Beats per Minute]",24,24,360,1)/60;
    }; 

    Wah = select3(sl, Wah2, Wah1, Wah3);

    b0 = Wah*(Wah*pow(fs,3)*(fs*(fs*(7.18082556296232e-31*fs + 1.2196809675607e-26) + 1.81635217972948e-23) + 9.8345184835125e-22) + pow(fs,2)*(fs*(fs*(fs*(-7.16633351212421e-31*fs - 1.22012125074374e-26) - 1.83126711766163e-23) - 1.21592229012527e-21) - 1.2608516331659e-20)) + pow(fs,2)*(fs*(fs*(fs*(-9.65744972703433e-31*fs - 3.08822188644282e-26) - 4.82624719521696e-23) - 2.88264605310366e-21) - 1.49007855810795e-20);

    b1 = Wah*(Wah*pow(fs,4)*(fs*(-4.30849533777739e-30*fs - 4.87872387024281e-26) - 3.63270435945895e-23) + pow(fs,2)*(pow(fs,2)*(fs*(4.29980010727452e-30*fs + 4.88048500297496e-26) + 3.66253423532326e-23) - 2.5217032663318e-20)) + pow(fs,2)*(pow(fs,2)*(fs*(5.7944698362206e-30*fs + 1.23528875457713e-25) + 9.65249439043393e-23) - 2.98015711621591e-20);

    b2 = Wah*(Wah*pow(fs,3)*(fs*(fs*(1.07712383444435e-29*fs + 6.09840483780351e-26) - 1.81635217972948e-23) - 2.95035554505375e-21) + pow(fs,2)*(fs*(fs*(fs*(-1.07495002681863e-29*fs - 6.1006062537187e-26) + 1.83126711766163e-23) + 3.64776687037582e-21) + 1.2608516331659e-20)) + pow(fs,2)*(fs*(fs*(fs*(-1.44861745905515e-29*fs - 1.54411094322141e-25) + 4.82624719521696e-23) + 8.64793815931099e-21) + 1.49007855810795e-20);

    b3 = Wah*(Wah*pow(fs,4)*(-1.43616511259246e-29*pow(fs,2) + 7.2654087189179e-23) + pow(fs,2)*(pow(fs,2)*(1.43326670242484e-29*pow(fs,2) - 7.32506847064652e-23) + 5.0434065326636e-20)) + pow(fs,2)*(pow(fs,2)*(1.93148994540687e-29*pow(fs,2) - 1.93049887808679e-22) + 5.96031423243182e-20);

    b4 = Wah*(Wah*pow(fs,3)*(fs*(fs*(1.07712383444435e-29*fs - 6.09840483780351e-26) - 1.81635217972948e-23) + 2.95035554505375e-21) + pow(fs,2)*(fs*(fs*(fs*(-1.07495002681863e-29*fs + 6.1006062537187e-26) + 1.83126711766163e-23) - 3.64776687037582e-21) + 1.2608516331659e-20)) + pow(fs,2)*(fs*(fs*(fs*(-1.44861745905515e-29*fs + 1.54411094322141e-25) + 4.82624719521696e-23) - 8.64793815931099e-21) + 1.49007855810795e-20);

    b5 = Wah*(Wah*pow(fs,4)*(fs*(-4.30849533777739e-30*fs + 4.87872387024281e-26) - 3.63270435945895e-23) + pow(fs,2)*(pow(fs,2)*(fs*(4.29980010727452e-30*fs - 4.88048500297496e-26) + 3.66253423532326e-23) - 2.5217032663318e-20)) + pow(fs,2)*(pow(fs,2)*(fs*(5.7944698362206e-30*fs - 1.23528875457713e-25) + 9.65249439043393e-23) - 2.98015711621591e-20);

    b6 = Wah*(Wah*pow(fs,3)*(fs*(fs*(7.18082556296232e-31*fs - 1.2196809675607e-26) + 1.81635217972948e-23) - 9.8345184835125e-22) + pow(fs,2)*(fs*(fs*(fs*(-7.16633351212421e-31*fs + 1.22012125074374e-26) - 1.83126711766163e-23) + 1.21592229012527e-21) - 1.2608516331659e-20)) + pow(fs,2)*(fs*(fs*(fs*(-9.65744972703433e-31*fs + 3.08822188644282e-26) - 4.82624719521696e-23) + 2.88264605310366e-21) - 1.49007855810795e-20);

    a0 = Wah*(Wah*pow(fs,2)*(fs*(fs*(fs*(-4.29845675581904e-29*fs - 3.19373566665743e-26) - 8.90038927961101e-23) - 4.87042253786579e-20) - 3.50713071672392e-19) + fs*(fs*(fs*(fs*(fs*(1.72206886126217e-28*fs + 1.1453389852842e-25) + 9.7683567600612e-23) + 5.2144154673581e-20) + 1.07969798611464e-18) + 5.31383441927866e-18)) + fs*(fs*(fs*(fs*(fs*(5.0345082751012e-30*fs + 1.05561747816346e-26) + 2.55142258602227e-22) + 1.48648313435063e-19) + 3.76182116601294e-18) + 3.09198451037471e-17) + 8.05126427163433e-17;

    a1 = Wah*(Wah*pow(fs,2)*(pow(fs,2)*(fs*(2.57907405349142e-28*fs + 1.27749426666297e-25) + 1.7800778559222e-22) - 7.01426143344783e-19) + fs*(fs*(pow(fs,2)*(fs*(-1.0332413167573e-27*fs - 4.5813559411368e-25) - 1.95367135201224e-22) + 2.15939597222928e-18) + 2.12553376771146e-17)) + fs*(fs*(pow(fs,2)*(fs*(-3.02070496506072e-29*fs - 4.22246991265385e-26) - 5.10284517204454e-22) + 7.52364233202588e-18) + 1.23679380414989e-16) + 4.8307585629806e-16;

    a2 = Wah*(Wah*pow(fs,2)*(fs*(fs*(fs*(-6.44768513372856e-28*fs - 1.59686783332872e-25) + 8.90038927961101e-23) + 1.46112676135974e-19) + 3.50713071672392e-19) + fs*(fs*(fs*(fs*(fs*(2.58310329189325e-27*fs + 5.726694926421e-25) - 9.7683567600612e-23) - 1.56432464020743e-19) - 1.07969798611464e-18) + 2.65691720963933e-17)) + fs*(fs*(fs*(fs*(fs*(7.55176241265181e-29*fs + 5.27808739081731e-26) - 2.55142258602227e-22) - 4.4594494030519e-19) - 3.76182116601294e-18) + 1.54599225518736e-16) + 1.20768964074515e-15;

    a3 = Wah*(Wah*pow(fs,2)*(pow(fs,2)*(8.59691351163808e-28*pow(fs,2) - 3.5601557118444e-22) + 1.40285228668957e-18) + pow(fs,2)*(pow(fs,2)*(-3.44413772252433e-27*pow(fs,2) + 3.90734270402448e-22) - 4.31879194445857e-18)) + pow(fs,2)*(pow(fs,2)*(-1.00690165502024e-28*pow(fs,2) + 1.02056903440891e-21) - 1.50472846640518e-17) + 1.61025285432687e-15;

    a4 = Wah*(Wah*pow(fs,2)*(fs*(fs*(fs*(-6.44768513372856e-28*fs + 1.59686783332872e-25) + 8.90038927961101e-23) - 1.46112676135974e-19) + 3.50713071672392e-19) + fs*(fs*(fs*(fs*(fs*(2.58310329189325e-27*fs - 5.726694926421e-25) - 9.7683567600612e-23) + 1.56432464020743e-19) - 1.07969798611464e-18) - 2.65691720963933e-17)) + fs*(fs*(fs*(fs*(fs*(7.55176241265181e-29*fs - 5.27808739081731e-26) - 2.55142258602227e-22) + 4.4594494030519e-19) - 3.76182116601294e-18) - 1.54599225518736e-16) + 1.20768964074515e-15;

    a5 = Wah*(Wah*pow(fs,2)*(pow(fs,2)*(fs*(2.57907405349142e-28*fs - 1.27749426666297e-25) + 1.7800778559222e-22) - 7.01426143344783e-19) + fs*(fs*(pow(fs,2)*(fs*(-1.0332413167573e-27*fs + 4.5813559411368e-25) - 1.95367135201224e-22) + 2.15939597222928e-18) - 2.12553376771146e-17)) + fs*(fs*(pow(fs,2)*(fs*(-3.02070496506072e-29*fs + 4.22246991265385e-26) - 5.10284517204454e-22) + 7.52364233202588e-18) - 1.23679380414989e-16) + 4.8307585629806e-16;

    a6 = Wah*(Wah*pow(fs,2)*(fs*(fs*(fs*(-4.29845675581904e-29*fs + 3.19373566665743e-26) - 8.90038927961101e-23) + 4.87042253786579e-20) - 3.50713071672392e-19) + fs*(fs*(fs*(fs*(fs*(1.72206886126217e-28*fs - 1.1453389852842e-25) + 9.7683567600612e-23) - 5.2144154673581e-20) + 1.07969798611464e-18) - 5.31383441927866e-18)) + fs*(fs*(fs*(fs*(fs*(5.0345082751012e-30*fs - 1.05561747816346e-26) + 2.55142258602227e-22) - 1.48648313435063e-19) + 3.76182116601294e-18) - 3.09198451037471e-17) + 8.05126427163433e-17;
};

process =  _<:*(dry),(*(wet) : *(gain) : fuzz : *(gain) : wah ):>_;
