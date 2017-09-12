/**
 * Competitive Programming - Collection of solved problems.
 *
 * @author        Simone Primarosa,(http://simoneprimarosa.com)
 * @link          (https://github.com/simonepri/competitive-programming)
 * @license       MIT License (https://opensource.org/licenses/MIT)
 */

#include <iostream>

#include <string>

using namespace std;

#define _ 0
#define O 6
#define A 4
#define B 8

#define ABO(a, b, c, d) a*1000 + b*100 + c*10 + d

int abotoi(char &c) {
  switch(c) {
    case 'O': return O;
    case 'A': return A;
    case 'B': return B;
  }
  return 0;
}

int abotoi(string &a) {
  int o = 0;
  int i = 0;
  if (a.size() == 3) {
    return abotoi(a[0]) * 10 + abotoi(a[1]);
  }
  return abotoi(a[0]);
}

int abotoi(string &a, string &b) {
  return abotoi(a) * 100 + abotoi(b);
}

string inherit(string &p, string &c) {
  bool rhp = p[p.size()-1] == '+';
  bool rhc = c[c.size()-1] == '+';

  switch (abotoi(p, c)) {
    case ABO(_,O, _,O):
    case ABO(_,A, _,O):
    case ABO(_,B, _,O):
    if (!rhp &&  rhc) return "{O+, B+, A+}";
    else              return "{O-, O+, B-, B+, A-, A+}";
    break;

    case ABO(_,O, _,A):
    case ABO(_,B, _,A):
    case ABO(_,B, A,B):
    if (!rhp &&  rhc) return "{AB+, A+}";
    else              return "{AB-, AB+, A-, A+}";
    break;

    case ABO(_,O, _,B):
    case ABO(_,A, _,B):
    case ABO(_,A, A,B):
    if (!rhp &&  rhc) return "{AB+, B+}";
    else              return "{AB-, AB+, B-, B+}";
    break;

    case ABO(_,A, _,A):
    case ABO(_,B, _,B):
    case ABO(A,B, _,A):
    case ABO(A,B, _,B):
    if (!rhp &&  rhc) return "{O+, AB+, B+, A+}";
    else              return "{O-, O+, AB-, AB+, B-, B+, A-, A+}";
    break;

    case ABO(A,B, A,B):
    if (!rhp &&  rhc) return "{AB+, B+, A+}";
    else              return "{AB-, AB+, B-, B+, A-, A+}";
    break;
  }
  return "IMPOSSIBLE";
}

string combine(string &p1, string &p2) {
  bool rhp1 = p1[p1.size()-1] == '+';
  bool rhp2 = p2[p2.size()-1] == '+';

  switch (abotoi(p1, p2)) {
    case ABO(_,O, _,O):
    if (!rhp1 && !rhp2) return "O-";
    else                return "{O-, O+}";

    case ABO(_,A, _,A):
    case ABO(_,A, _,O):
    case ABO(_,O, _,A):
    if (!rhp1 && !rhp2) return "{O-, A-}";
    else                return "{O-, O+, A-, A+}";

    case ABO(_,B, _,B):
    case ABO(_,B, _,O):
    case ABO(_,O, _,B):
    if (!rhp1 && !rhp2) return "{O-, B-}";
    else                return "{O-, O+, B-, B+}";

    case ABO(A,B, _,O):
    case ABO(_,O, A,B):
    if (!rhp1 && !rhp2) return "{B-, A-}";
    else                return "{B-, B+, A-, A+}";

    case ABO(A,B, A,B):
    case ABO(A,B, _,A):
    case ABO(A,B, _,B):
    case ABO(_,B, A,B):
    case ABO(_,A, A,B):
    if (!rhp1 && !rhp2) return "{AB-, B-, A-}";
    else                return "{AB-, AB+, B-, B+, A-, A+}";

    case ABO(_,A, _,B):
    case ABO(_,B, _,A):
    if (!rhp1 && !rhp2) return "{O-, AB-, B-, A-}";
    else                return "{O-, O+, AB-, AB+, B-, B+, A-, A+}";
  }
  return "";
}

int main() {
  ios_base::sync_with_stdio(false); // faster I/O

  int t = 0;
  string p1, p2, c1;
  while (true) {
    t++;
    cin >> p1 >> p2 >> c1;
    if (p1[0] == 'E') break;

    if (p1[0] == '?') {
      string x = inherit(p2, c1);
      cout << "Case " << t << ": " << inherit(p2, c1) << " " << p2 << " " << c1 << endl;
    } else if (p2[0] == '?') {
      cout << "Case " << t << ": " << p1 << " " << inherit(p1, c1) << " " << c1 << endl;
    } else if (c1[0] == '?') {
      cout << "Case " << t << ": " << p1 << " " << p2 << " " << combine(p1, p2) << endl;
    }
  }

  return 0;
}
