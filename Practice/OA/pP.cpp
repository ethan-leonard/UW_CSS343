#include <vector>
#include <algorithm>

using namespace std;

long long getMaxPlaylists(int k, std::vector<int>& videoCategory) {
    sort(videoCategory.begin(), videoCategory.end(), greater<int>());

    long long maxPlaylists = 0;
    long long videosLeft = 0;

    for (int i : videoCategory) {
        videosLeft+=i;
    }

    while (videosLeft >= k && videoCategory.size() >= k) {
        if (videoCategory[k-1] > 0) {
            for (int i = 0; i < k; i++) {
                videoCategory[i]--;
                videosLeft--;
            }

            maxPlaylists++;

            sort(videoCategory.begin(), videoCategory.end(), greater<int>());
        } else {
            break;
        }
    } return maxPlaylists;

}