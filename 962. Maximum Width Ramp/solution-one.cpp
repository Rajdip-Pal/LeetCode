#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        int n = nums.size();
        std::stack<int> s;
        
        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        
        int maxWidth = 0;
        
        // Step 2: Traverse from the end and find maximum width ramp
        for (int j = n - 1; j >= 0; --j) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                maxWidth = std::max(maxWidth, j - s.top());
                s.pop();
            }
        }
        
        return maxWidth;
    }
};

int main (int argc, char const *argv[]) {
    Solution s;
    std::vector<int> nums = {9,8,7,1,0};
    std::cout << s.maxWidthRamp(nums) << std::endl;
    return 0;
}

/**
 * Possible cases and solutions :---
 * 
 * [6,0,8,2,1,5]
 * (i,j) => (1,5)
 * result => 4
 * 
 * [9,8,1,0,1,9,4,0,4,1]
 * (i,j) => (2,9)
 * result => 7
 * 
 * [30,9,8,4,5,3,2,1,19,25]
 * (i,j) => (1,9)
 * result => 8
 * 
 * [15,9,8,4,5,3,2,19,10]
 * (i,j) => (1,8)
 * result => 7
 * 
 * [2,1,3]
 * [2,7,2,2,7]
 * [1,9,7,0,6,5,0,7,2,3]
 * [74,37,98,98,97,96,94,93,92,89,85,83,83,82,82,82,80,77,76,75,75,74,73,72,98,70,16,69,87,29,67,65,63,63,63,62,62,61,60,60,48,59,58,53,53,53,52,52,50,12,47,47,46,46,43,43,42,40,38,38,92,35,35,35,34,34,33,31,31,31,31,30,27,26,25,25,25,23,23,23,20,18,16,14,14,14,13,12,11,10,9,7,7,7,7,5,5,5,5,89]
 * [277,227,215,172,164,236,144,11,212,158,46,256,47,114,32,56,54,8,1,107,11,298,179,191,175,86,78,90,218,1,65,284,210,184,15,295,265,248,35,7,23,114,265,138,220,58,27,93,52,16,206,299,52,285,34,263,127,214,291,34,99,104,108,84,68,60,225,143,262,7,36,262,69,123,170,30,154,297,212,72,230,234,168,263,216,118,284,298,175,84,280,12,50,233,73,139,193,158,49,181,236,90,170,297,189,87,270,34,186,149,124,101,58,128,114,247,23,101,53,271,40,233,42,219,242,232,199,104,116,206,170,249,200,89,142,177,5,3,212,17,134,78,1,163,215,262,241,110,130,23,264,90,105,43,99,210,91,259,68,121,173,263,223,131,136,112,1,217,21,85,19,224,116,81,16,51,286,64,81,27,225,266,295,247,58,273,129,185,124,191,264,55,146,264,91,176,56,165,14,132,127,38,30,251,287,181,45,285,71,48,54,163,48,151,210,40,179,234,172,15,85,0,298,121,159,171,263,31,147,186,98,220,160,186,259,2,92,68,136,277,195,170,150,49,290,112,186,215,35,9,238,287,80,210,158,49,62,280,208,85,288,26,35,8,270,272,204,248,181,142,259,38,198,194,255,183,48,109,196,14,269,272,64,7,113,172,182,134,207,276,293,251,188,270,123,184,79,30,33,195]
 * [29,28,28,26,25,24,9,23,21,9,18,17,14,12,3,11,10,8,8,10,22,6,5,20,5,2,1,1,1,0]
 * [999,998,997,995,993,992,992,991,991,990,989,989,988,987,986,985,983,978,978,978,978,977,977,975,975,974,973,972,971,970,970,968,968,967,967,966,965,964,963,962,962,961,960,960,960,959,957,956,955,955,953,953,953,952,951,950,946,946,944,944,942,941,941,940,940,940,938,937,935,934,934,933,933,931,930,930,929,929,929,928,927,926,925,925,925,923,923,919,918,915,915,914,913,913,912,912,911,910,909,908,907,907,907,907,907,899,898,896,895,895,895,894,893,892,891,890,889,888,888,887,887,887,886,886,883,882,882,882,880,878,877,877,877,876,876,876,875,874,874,872,871,871,871,870,869,868,867,866,865,865,865,864,861,855,855,855,851,851,851,848,847,846,845,845,844,843,842,841,840,840,838,838,836,834,833,833,832,830,828,828,827,826,825,825,825,824,822,822,819,819,819,816,815,814,813,813,812,812,811,810,810,810,810,808,808,807,806,805,804,801,801,799,798,798,797,796,87,793,792,791,791,789,787,784,784,778,777,776,776,775,774,774,773,771,771,769,768,767,767,767,766,765,765,764,762,761,760,759,758,758,756,754,752,751,750,750,750,750,749,749,748,747,747,746,746,746,745,744,744,741,741,741,740,739,739,738,737,737,737,734,733,732,732,731,731,730,729,726,726,725,725,725,723,722,722,722,720,716,716,716,716,713,713,711,709,708,708,707,706,704,704,703,702,700,699,699,697,696,696,696,695,694,694,692,449,692,690,690,690,689,688,687,687,171,686,683,683,682,682,682,680,680,680,679,678,677,677,676,676,676,676,675,674,673,669,669,668,668,666,927,665,665,665,662,661,661,660,659,657,655,655,654,653,653,652,652,651,650,646,646,645,644,643,642,639,81,636,632,631,630,628,625,623,623,623,622,621,620,620,618,618,618,614,610,609,609,608,607,606,606,605,605,603,603,602,601,601,601,600,600,599,598,596,595,594,593,593,593,592,592,592,591,591,589,588,586,586,585,584,584,583,582,582,578,576,576,576,575,572,572,572,570,570,569,569,568,566,566,565,563,562,560,560,560,556,555,554,551,551,550,550,548,548,548,546,546,546,545,544,543,980,541,540,539,536,536,533,533,530,529,529,529,529,527,525,525,523,520,520,519,517,516,516,515,514,511,509,508,508,507,504,503,502,500,500,499,498,497,496,496,494,492,490,490,490,488,487,486,485,686,484,482,480,480,480,480,479,479,479,478,477,476,475,475,473,473,471,471,470,469,469,468,468,466,466,463,759,461,460,460,459,457,457,455,454,453,453,452,451,450,449,448,447,446,443,439,438,437,436,435,435,433,433,430,429,427,427,423,422,422,419,419,418,417,414,412,409,407,406,405,403,402,402,401,400,397,397,393,392,392,390,388,388,387,387,387,386,386,383,383,382,381,380,378,378,377,376,376,375,373,373,369,369,369,368,366,365,992,364,363,363,363,362,362,361,360,359,359,359,356,356,355,354,353,352,351,351,350,349,348,347,347,346,344,341,341,341,340,337,337,336,335,334,333,332,331,329,329,329,328,326,326,325,324,324,320,319,317,315,314,314,313,312,310,309,309,308,308,307,306,306,305,305,301,301,300,300,297,294,294,294,294,293,293,292,291,291,291,290,288,286,285,284,284,282,280,280,278,275,273,272,272,271,269,269,268,268,267,267,265,264,262,261,260,258,257,256,251,251,250,248,248,247,244,244,243,243,241,238,232,231,230,230,229,229,228,227,226,226,225,224,222,221,220,219,219,217,216,216,215,214,212,212,211,209,209,206,205,205,205,205,203,203,202,201,201,201,200,200,199,199,198,198,198,197,196,196,195,190,189,189,189,189,188,186,185,185,185,185,184,184,183,183,183,181,181,177,177,176,176,175,175,172,171,171,168,168,164,164,164,162,161,161,158,158,158,157,156,156,152,149,149,146,142,140,138,138,138,137,136,133,133,131,131,130,130,128,128,128,127,127,125,124,122,120,119,119,119,119,118,116,115,115,115,115,113,112,110,109,108,108,106,106,105,104,101,100,99,97,96,94,93,93,93,93,92,90,90,90,90,86,84,82,82,79,78,78,77,75,75,72,72,71,70,70,66,65,65,61,60,59,57,57,56,56,54,54,54,53,53,53,52,50,50,49,49,49,47,47,46,45,44,43,43,43,41,40,38,37,36,36,36,36,35,35,34,33,32,31,30,30,900,26,24,20,20,19,18,18,18,18,17,17,16,16,14,10,10,7,7,6,5,5,4,3,3,3,3,2,0]
 * [999,999,999,996,994,994,994,993,993,990,990,990,987,987,986,985,984,983,983,983,982,981,980,979,979,979,978,977,975,975,974,972,972,971,971,970,969,968,968,967,967,966,966,924,966,963,962,960,959,958,956,956,956,956,956,951,951,951,948,946,946,943,941,941,938,937,936,936,932,931,930,929,505,928,927,927,925,923,923,920,919,919,918,916,914,914,914,911,911,910,908,908,905,904,902,473,900,900,900,899,899,899,898,897,897,897,896,895,892,891,890,889,888,888,887,887,884,884,883,880,880,880,879,878,878,878,876,875,875,874,873,871,869,868,867,866,865,864,862,862,861,858,856,851,850,849,849,849,846,846,845,845,845,844,844,842,840,840,838,838,837,836,833,833,833,831,830,829,829,828,827,827,827,826,824,821,820,817,815,815,812,812,811,810,810,810,808,807,805,804,804,802,802,802,802,801,800,406,799,797,797,795,795,795,793,793,792,792,790,786,786,786,785,785,783,783,781,780,779,778,777,775,774,774,773,773,772,771,771,770,769,769,847,767,767,767,764,764,764,762,761,759,758,757,755,755,753,751,751,751,750,748,748,747,746,746,745,745,742,742,740,740,740,740,737,734,727,726,725,724,723,722,721,720,719,719,718,717,717,716,715,715,714,713,713,713,713,713,711,708,706,702,699,698,697,696,696,695,693,693,693,692,689,687,687,687,684,684,684,683,682,681,681,681,680,679,679,677,677,675,672,671,671,671,670,670,667,667,666,666,665,664,664,664,663,663,663,662,662,659,659,659,658,654,653,653,649,648,647,647,646,644,639,637,637,636,635,631,631,629,629,628,628,628,628,704,625,625,621,620,618,618,615,612,610,610,610,610,609,609,606,605,602,601,601,601,600,598,597,594,593,593,591,589,585,585,584,583,583,582,581,580,579,579,579,578,578,577,576,576,575,574,574,573,572,570,569,568,567,566,565,565,563,563,563,561,561,561,560,559,558,556,554,551,548,546,545,544,543,542,541,541,537,533,533,532,531,531,529,528,525,523,523,522,521,521,520,519,514,513,512,511,510,510,508,507,507,507,503,501,500,499,497,494,494,492,491,491,489,487,487,486,485,485,484,483,483,482,482,480,480,480,480,479,479,478,478,478,477,477,477,476,475,473,472,470,470,468,468,466,463,462,462,462,461,460,460,459,459,458,456,454,453,450,876,449,449,448,447,446,444,443,443,442,442,441,441,440,439,439,438,437,436,434,432,431,431,430,428,428,428,425,424,424,422,421,421,420,419,419,419,418,418,417,416,415,414,412,411,411,410,409,409,408,408,408,407,405,405,404,404,402,400,399,398,396,396,396,395,395,395,390,389,388,387,387,383,381,381,381,380,380,379,379,379,379,377,376,375,374,374,374,374,373,373,373,372,372,370,369,369,368,366,365,363,361,360,359,359,357,356,356,356,354,352,351,349,348,348,347,346,346,345,342,342,339,338,337,337,336,335,334,333,331,330,330,329,328,328,327,327,326,324,324,323,321,321,320,320,318,318,317,316,316,315,314,313,312,310,308,308,307,307,306,306,303,302,299,299,297,295,294,294,293,293,292,289,289,287,287,285,283,280,277,276,272,272,272,271,270,270,268,268,267,266,265,265,263,262,262,261,259,258,257,257,256,256,255,254,251,251,250,250,250,249,247,247,247,243,242,242,239,239,238,236,235,235,232,232,231,230,230,230,229,228,227,225,224,223,221,220,218,218,217,217,217,216,216,214,214,211,210,209,208,207,204,199,199,198,198,198,196,196,196,196,195,195,193,191,191,190,188,186,185,181,180,179,178,178,177,176,174,173,173,171,170,170,170,170,169,169,730,168,166,165,165,163,159,159,158,157,156,155,152,152,151,150,148,146,144,144,143,143,143,141,140,140,138,132,131,130,130,129,128,128,127,126,126,125,121,120,119,118,118,115,114,114,114,114,113,112,112,112,111,110,110,107,106,106,106,105,105,102,102,98,97,96,96,96,93,92,91,91,90,89,89,88,88,88,88,87,85,85,81,80,80,79,78,78,78,78,78,77,76,75,74,74,57,74,72,72,71,70,70,69,69,69,68,68,68,68,7,65,61,61,60,59,59,59,58,56,55,54,53,53,53,52,52,52,51,51,51,50,50,48,48,48,47,47,46,45,44,42,38,38,37,36,36,34,34,33,33,33,32,32,32,32,31,31,30,29,29,28,27,26,26,22,22,21,18,17,17,17,16,14,14,14,13,11,11,11,10,9,8,8,7,4,2,0,0]
 * 
 * 
 * 
 * 
 */


// std::vector<int> left(length), right(length);
// left[0] = -1;
// right[length-1] = length;
// for (int i = 1; i < length; i++) {
//     left[i] = i-1;
//     while (nums[left[i]] > nums[i])
//         left[i] = left[left[i]];
// }
// for (int i = length-2; i >= 0; i--) {
//     right[i] = i+1;
//     while (nums[right[i]] < nums[i])
//         right[i] = right[right[i]];
// }
// int max_width = 0;
// for (int i = 0; i < length; i++)
//     max_width = std::max(max_width, right[left[i]] - left[i] - 1);
// return max_width;
