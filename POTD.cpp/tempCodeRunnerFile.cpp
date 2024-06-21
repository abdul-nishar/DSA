
long double maxVolume(double perimeter, double area) {
        long double expression = (perimeter*perimeter) - (24.0 * area);
        cout << "EXPRESSION: " << fixed <<  expression << endl;
        long double discriminant = sqrt(expression);
        cout << "DISCRIMINANT: " << fixed <<  discriminant << endl;
        
        long double height1 = (perimeter + discriminant) / 12.0;
        cout << "HEIGHT1: " << fixed <<  height1 << endl;

        long double height2 = (perimeter - discriminant) / 12.0;
        cout << "HEIGHT2: " << fixed <<  height2 << endl;
        height2 = round(height2 * 100.0) / 100.0;
        
        long double volume1 = (area*height1)/2.0 - (perimeter*height1*height1)/4.0 + (height1*height1*height1);
        cout << "VOLUME1: " << fixed <<  volume1 << endl;

        long double volume2 = (area*height2)/2.0 - (perimeter*height2*height2)/4.0 + (height2*height2*height2);
        cout << "VOLUME2: " << fixed <<  volume2 << endl;
        
        long double result = max(volume1,volume2);
        result = round(result * 100.0) / 100.0;
        return result;
    }