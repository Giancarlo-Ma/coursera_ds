#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};


bool cmp(struct Segment a, struct Segment b)
{
	int s1 = a.end;
	int s2 = b.end;
	return s1 < s2;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(), segments.end(), cmp);
  if(segments.size() != 0) points.push_back(segments[0].end);
  int curr = 0;
  for(int i = 1; i < segments.size(); i++) {
    // cout << "start: " << segments[i].start << " end: " << segments[i].end << endl;
    if(!(points[curr] >= segments[i].start && points[curr] <= segments[i].end)) {
      points.push_back(segments[i].end);
      curr++;
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
