#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double Su = 0;
    double Sy = 0;
    double SeDash = 0;
    double Ka = 0;
    double KaA = 0;
    double KaB = 0;
    int UserChoise = 0;   //surface finish
    double d = 0;
    double Kb = 0;
    double Reability = 0;
    double Kc = 0;
    double Se = 0;
    double Kt = 0;
    int UserCHoise2 = 0;   //Stress concentration points
    double Fmax = 0;
    double Fmin = 0;
    double Qn = 0;
    double Ke = 0;
    double SigmaMax = 0;
    double SigmaMin = 0;
    double Area = 0;
    double Mmax = 0;
    double Mmin = 0;
    double I = 0;
    double SigmaMean = 0;
    double SigmaAllowable = 0;
    double n = 0;

    cout << "Enter Ultimate tensile strength in Mpa:";   //check name
    cin >> Su;

    cout << "Enter Yield strength in Mpa:";     //check name
    cin >> Sy;

    if (Su < 330) {
        SeDash = 0.4 * Su;
    }
    else if (Su <= 600) {
        SeDash = 0.45 * Su;
    }
    else if (Su <= 1400) {
        SeDash = 0.5 * Su;
    }

    cout << " If you need the surface finish Ground press 1 and if you need Machined or cold-rolled press 2 and if you need Hot-rolled press 3 and if you need As-forged press 4:";
    cin >> UserChoise;

    if (UserChoise == 1) {
        KaA = 1.58;
        KaB = -0.005;
    }
    if (UserChoise == 2) {
        KaA = 4.51;
        KaB = -0.265;
    }
    if (UserChoise == 3) {
        KaA = 57.7;
        KaB = -0.718;
    }
    if (UserChoise == 4) {
        KaA = 272;
        KaB = -0.995;
    }

    Ka = KaA * pow(Su, KaB);
    cout << "Enter d in mm if exist if not enter 0:";
    cin >> d;

    if (d <= 8 && d != 0) {
        Kb = 1;
    }
    if (d > 8 && d <= 250) {
        Kb = 1.89 * pow(d, -0.097);
    }
    cout << "Enter the Reability % if exist if not enter 0:";
    cin >> Reability;
    if (Reability == 50) {
        Kc = 1;
    }
    if (Reability == 90) {
        Kc = 0.897;
    }
    if (Reability == 99) {
        Kc = 0.814;
    }
    if (Reability == 99.9) {
        Kc = 0.753;
    }
    if (Reability == 99.99) {
        Kc = 0.702;
    }
    if (Reability == 99.999) {
        Kc = 0.659;
    }

    Se = Ka * Kb * Kc * SeDash;

    cout << "Determine the type of stress concentration point, if Bar in tension or simple compression with a transverse hole press 1, if Rectangular bar with a transverse hole in bending press 2, if Notched rectangular bar in tension or simple compression press 3:";
    cin >> UserCHoise2;
    cout << "Enter Kt:";
    cin >> Kt;

    cout << "Enter Qn:";
    cin >> Qn;

    Ke = 1 + Qn * (Kt - 1);

    if (UserCHoise2 == 1) {
        cout << "Enter the Max Force:";
        cin >> Fmax;

        cout << "Enter the Min Force:";
        cin >> Fmin;

        cout << "Enter the thickness:";
        double t;
        cin >> t;

        cout << "Enter the Width:";
        double w;
        cin >> w;

        cout << "Enter the Hole diameter:";
        double dHole;
        cin >> dHole;

        Area = (w - dHole) * t;
        SigmaMax = Fmax / Area;
        SigmaMin = Fmin / Area;
    }

    if (UserCHoise2 == 2) {
        cout << "Enter the Max Moment:";
        cin >> Mmax;

        cout << "Enter the Min Moment:";
        cin >> Mmin;

        cout << "Enter the thickness:";
        double h;
        cin >> h;

        cout << "Enter the Width:";
        double b;
        cin >> b;

        cout << "Enter the Hole diameter:";
        double dHole;
        cin >> dHole;

        I = (b * pow(h, 3)) / 12;
        SigmaMax = Mmax / I;
        SigmaMin = Mmin / I;
    }

    if (UserCHoise2 == 3) {
        cout << "Enter the Max Force:";
        cin >> Fmax;

        cout << "Enter the Min Force:";
        cin >> Fmin;

        cout << "Enter the thickness:";
        double t;
        cin >> t;

        cout << "Enter the Width:";
        double w;
        cin >> w;

        cout << "Enter the Notch Radius:";
        double Nradius;
        cin >> Nradius;

        double d = w - 2 * Nradius;
        Area = (w - d) * t;

        SigmaMax = Fmax / Area;
        SigmaMin = Fmin / Area;
    }

    SigmaMean = (SigmaMax + SigmaMin) / 2;
    SigmaAllowable = (SigmaMax - SigmaMin) / 2;
    cout << "Apply Goodman" << endl;

    n = 1 / (((Ke * SigmaAllowable) / Se) + (SigmaMean / Su));
    cout << n << endl;

    if (n > 1)
        cout << "The Part has infinite life";

    return 0;
}
