#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "FFT.h"

#define DATA_LENGTH 1024
                        
int main(int argc, char** argv) {

	double x_data[DATA_LENGTH] = {1.00000,1.00000,0.99999,0.99994,0.99980,0.99951,0.99898,0.99810,0.99677,0.99482,0.99211,0.98846,0.98367,0.97753,0.96982,0.96029,0.94870,0.93478,0.91825,0.89886,0.87631,0.85033,0.82067,0.78706,0.74928,0.70711,0.66037,0.60893,0.55269,0.49163,0.42578,0.35524,0.28020,0.20094,0.11785,0.03141,-0.05777,-0.14898,-0.24138,-0.33400,-0.42578,-0.51552,-0.60193,-0.68363,-0.75918,-0.82708,-0.88582,-0.93388,-0.96982,-0.99227,-1.00000,-0.99196,-0.96732,-0.92555,-0.86644,-0.79016,-0.69727,-0.58880,-0.46626,-0.33163,-0.18738,-0.03643,0.11785,0.27174,0.42123,0.56208,0.69002,0.80082,0.89044,0.95524,0.99211,0.99867,0.97339,0.91575,0.82637,0.70711,0.56104,0.39253,0.20709,0.01131,-0.18738,-0.38094,-0.56104,-0.71944,-0.84834,-0.94088,-0.99147,-0.99624,-0.95336,-0.86329,-0.72897,-0.55583,-0.35171,-0.12658,0.10786,0.33874,0.55269,0.73666,0.87872,0.96889,1.00000,0.96827,0.87387,0.72118,0.51874,0.27899,0.01759,-0.24747,-0.49710,-0.71242,-0.87631,-0.97481,-0.99847,-0.94341,-0.81196,-0.61291,-0.36110,-0.07658,0.21692,0.49382,0.72897,0.89995,0.98939,0.98689,0.89044,0.70711,0.45287,0.15147,-0.16759,-0.47181,-0.72897,-0.91063,-0.99544,-0.97193,-0.84026,-0.61291,-0.31379,0.02387,0.36110,0.65753,0.87631,0.98884,0.97884,0.84500,0.60193,0.27899,-0.08284,-0.43599,-0.73240,-0.93024,-1.00000,-0.92931,-0.72552,-0.41552,-0.04271,0.33874,0.67162,0.90429,0.99898,0.93830,0.72897,0.40176,0.00754,-0.39022,-0.72552,-0.94088,-0.99752,-0.88288,-0.61390,-0.23528,0.18738,0.57860,0.86644,0.99602,0.94045,0.70711,0.33756,-0.09911,-0.51874,-0.83821,-0.99211,-0.94669,-0.70799,-0.32213,0.13281,0.56208,0.87387,0.99924,0.90801,0.61687,0.18738,-0.28622,-0.69727,-0.95067,-0.98543,-0.79016,-0.40750,0.07407,0.54006,0.87691,1.00000,0.87570,0.53158,0.05150,-0.44388,-0.82708,-0.99677,-0.90536,-0.57346,-0.08660,0.42578,0.82424,0.99752,0.89440,0.54006,0.03141,-0.48835,-0.86956,-0.99955,-0.83684,-0.42578,0.11410,0.62180,0.94257,0.97564,0.70711,0.21692,-0.34346,-0.79704,-0.99725,-0.87631,-0.46959,0.09286,0.62671,0.95336,0.96029,0.64129,0.10161,-0.47513,-0.88871,-0.99211,-0.74510,-0.23161,0.36696,0.83477,0.99951,0.79704,0.29824,-0.31379,-0.80975,-1.00000,-0.80828,-0.30423,0.31975,0.82067,0.99951,0.78161,0.24991,-0.38442,-0.86456,-0.99211,-0.71065,-0.13281,0.50254,0.92791,0.96029,0.58167,-0.04899,-0.66037,-0.98478,-0.87631,-0.37862,0.28983,0.82990,0.99544,0.70711,0.09286,-0.56623,-0.96339,-0.90958,-0.42578,0.26205,0.82637,0.99375,0.67903,0.03141,-0.63354,-0.98648,-0.84834,-0.28381,0.42578,0.92072,0.94547,0.48285,-0.23161,-0.82708,-0.98939,-0.62867,0.06781,0.72983,1.00000,0.72811,0.05777,-0.64610,-0.99443,-0.79016,-0.14277,0.58677,0.98543,0.82282,0.18738,-0.55792,-0.98085,-0.83130,-0.19232,0.56208,0.98367,0.81706,0.15768,-0.59891,-0.99211,-0.77767,-0.08284,0.66507,0.99955,0.70711,-0.03267,-0.75343,-0.99443,-0.59690,0.18738,0.85165,0.96064,0.43825,-0.37512,-0.94088,-0.87872,-0.22550,0.58167,0.99508,0.72897,-0.03895,-0.78161,-0.98252,-0.49710,0.33874,0.93699,0.87080,0.18244,-0.63839,-1.00000,-0.63646,0.19232,0.88170,0.92219,0.27899,-0.57346,-0.99795,-0.67162,0.16388,0.87631,0.91974,0.25599,-0.60693,-0.99999,-0.61291,0.25599,0.92460,0.86138,0.11161,-0.72897,-0.98434,-0.44388,0.45846,0.98788,0.70711,-0.15768,-0.89328,-0.88582,-0.13655,0.72897,0.97960,0.39830,-0.52410,-0.99847,-0.61291,0.30423,0.95816,0.77530,-0.08910,-0.87631,-0.88756,-0.10786,0.76971,0.95635,0.27899,-0.65279,-0.99063,-0.42123,0.53689,1.00000,0.53477,-0.43032,-0.99347,-0.62180,0.33874,0.97884,0.68546,-0.26569,-0.96237,-0.72897,0.21324,0.94870,0.75508,-0.18244,-0.94088,-0.76569,0.17379,0.94045,0.76163,-0.18738,-0.94750,-0.74258,0.22305,0.96064,0.70711,-0.28020,-0.97700,-0.65279,0.35759,0.99211,0.57655,-0.45287,-0.99990,-0.47513,0.56208,0.99273,0.34582,-0.67903,-0.96168,-0.18738,0.79475,0.89720,0.00126,-0.89720,-0.79016,0.20709,0.97133,0.63354,-0.42692,-1.00000,-0.42464,0.64129,0.96571,0.16759,-0.82708,-0.85362,0.12409,0.95635,0.65564,-0.42578,-0.99965,-0.37512,0.70176,0.93162,0.03141,-0.90801,-0.73836,0.33756,0.99880,0.42578,-0.67626,-0.93699,-0.02639,0.91825,0.70711,-0.39830,-0.99934,-0.32808,0.76326,0.87631,-0.13903,-0.97564,-0.54745,0.59387,0.96029,0.06781,-0.91473,-0.69002,0.44951,0.99211,0.21078,-0.85362,-0.77131,0.35171,0.99951,0.28983,-0.81561,-0.80605,0.31021,1.00000,0.30782,-0.81196,-0.80232,0.32808,0.99951,0.26569,-0.84365,-0.75918,0.40406,0.99211,0.16140,-0.90159,-0.66695,0.53158,0.96029,-0.00754,-0.96505,-0.51012,0.69456,0.87631,-0.23772,-0.99980,-0.27416,0.86138,0.70711,-0.51012,-0.95888,0.04271,0.98011,0.42578,-0.77925,-0.79092,0.41323,0.98085,0.03141,-0.96732,-0.46070,0.76569,0.79323,-0.42578,-0.97424,0.01759,0.98205,0.38442,-0.82708,-0.71506,0.54534,0.92791,-0.18862,-1.00000,-0.18615,0.93162,0.52624,-0.74258,-0.79016,0.46626,0.95144,-0.14277,-0.99971,-0.18738,0.93917,0.48835,-0.78551,-0.73240,0.56208,0.90159,-0.29584,-0.98788,0.01382,0.99211,0.25963,-0.92219,-0.50471,0.79092,0.70711,-0.61390,-0.85817,0.40750,0.95449,-0.18738,-0.99706,-0.03267,0.99029,0.24138,-0.94088,-0.43032,0.85688,0.59387,-0.74678,-0.72897,0.61885,0.83477,-0.48065,-0.91218,0.33874,0.96339,-0.19848,-0.99147,0.06404,1.00000,0.06154,-0.99273,-0.17626,0.97339,0.27899,-0.94547,-0.36929,0.91218,0.44726,-0.87631,-0.51336,0.84026,0.56830,-0.80605,-0.61291,0.77530,0.64801,-0.74928,-0.67441,0.72897,0.69275,-0.71506,-0.70354,0.70799,0.70711,-0.70799,-0.70354,0.71506,0.69275,-0.72897,-0.67441,0.74928,0.64801,-0.77530,-0.61291,0.80605,0.56830,-0.84026,-0.51336,0.87631,0.44726,-0.91218,-0.36929,0.94547,0.27899,-0.97339,-0.17626,0.99273,0.06154,-1.00000,0.06404,0.99147,-0.19848,-0.96339,0.33874,0.91218,-0.48065,-0.83477,0.61885,0.72897,-0.74678,-0.59387,0.85688,0.43032,-0.94088,-0.24138,0.99029,0.03267,-0.99706,0.18738,0.95449,-0.40750,-0.85817,0.61390,0.70711,-0.79092,-0.50471,0.92219,0.25963,-0.99211,0.01382,0.98788,-0.29584,-0.90159,0.56208,0.73240,-0.78551,-0.48835,0.93917,0.18738,-0.99971,0.14277,0.95144,-0.46626,-0.79016,0.74258,0.52624,-0.93162,-0.18615,1.00000,-0.18862,-0.92791,0.54534,0.71506,-0.82708,-0.38442,0.98205,-0.01759,-0.97424,0.42578,0.79323,-0.76569,-0.46070,0.96732,0.03141,-0.98085,0.41323,0.79092,-0.77925,-0.42578,0.98011,-0.04271,-0.95888,0.51012,0.70711,-0.86138,-0.27416,0.99980,-0.23772,-0.87631,0.69456,0.51012,-0.96505,0.00754,0.96029,-0.53158,-0.66695,0.90159,0.16140,-0.99211,0.40406,0.75918,-0.84365,-0.26569,0.99951,-0.32808,-0.80232,0.81196,0.30782,-1.00000,0.31021,0.80605,-0.81561,-0.28983,0.99951,-0.35171,-0.77131,0.85362,0.21078,-0.99211,0.44951,0.69002,-0.91473,-0.06781,0.96029,-0.59387,-0.54745,0.97564,-0.13903,-0.87631,0.76326,0.32808,-0.99934,0.39830,0.70711,-0.91825,-0.02639,0.93699,-0.67626,-0.42578,0.99880,-0.33756,-0.73836,0.90801,0.03141,-0.93162,0.70176,0.37512,-0.99965,0.42578,0.65564,-0.95635,0.12409,0.85362,-0.82708,-0.16759,0.96571,-0.64129,-0.42464,1.00000,-0.42692,-0.63354,0.97133,-0.20709,-0.79016,0.89720,0.00126,-0.89720,0.79475,0.18738,-0.96168,0.67903,0.34582,-0.99273,0.56208,0.47513,-0.99990,0.45287,0.57655,-0.99211,0.35759,0.65279,-0.97700,0.28020,0.70711,-0.96064,0.22305,0.74258,-0.94750,0.18738,0.76163,-0.94045,0.17379,0.76569,-0.94088,0.18244,0.75508,-0.94870,0.21324,0.72897,-0.96237,0.26569,0.68546,-0.97884,0.33874,0.62180,-0.99347,0.43032,0.53477,-1.00000,0.53689,0.42123,-0.99063,0.65279,0.27899,-0.95635,0.76971,0.10786,-0.88756,0.87631,-0.08910,-0.77530,0.95816,-0.30423,-0.61291,0.99847,-0.52410,-0.39830,0.97960,-0.72897,-0.13655,0.88582,-0.89328,0.15768,0.70711,-0.98788,0.45846,0.44388,-0.98434,0.72897,0.11161,-0.86138,0.92460,-0.25599,-0.61291,0.99999,-0.60693,-0.25599,0.91974,-0.87631,0.16388,0.67162,-0.99795,0.57346,0.27899,-0.92219,0.88170,-0.19232,-0.63646,1.00000,-0.63839,-0.18244,0.87080,-0.93699,0.33874,0.49710,-0.98252,0.78161,-0.03895,-0.72897,0.99508,-0.58167,-0.22550,0.87872,-0.94088,0.37512,0.43825,-0.96064,0.85165,-0.18738,-0.59690,0.99443,-0.75343,0.03267,0.70711,-0.99955,0.66507,0.08284,-0.77767,0.99211,-0.59891,-0.15768,0.81706,-0.98367,0.56208,0.19232,-0.83130,0.98085,-0.55792,-0.18738,0.82282,-0.98543,0.58677,0.14277,-0.79016,0.99443,-0.64610,-0.05777,0.72811,-1.00000,0.72983,-0.06781,-0.62867,0.98939,-0.82708,0.23161,0.48285,-0.94547,0.92072,-0.42578,-0.28381,0.84834,-0.98648,0.63354,0.03141,-0.67903,0.99375,-0.82637,0.26205,0.42578,-0.90958,0.96339,-0.56623,-0.09286,0.70711,-0.99544,0.82990,-0.28983,-0.37862,0.87631,-0.98478,0.66037,-0.04899,-0.58167,0.96029,-0.92791,0.50254,0.13281,-0.71065,0.99211,-0.86456,0.38442,0.24991,-0.78161,0.99951,-0.82067,0.31975,0.30423,-0.80828,1.00000,-0.80975,0.31379,0.29824,-0.79704,0.99951,-0.83477,0.36696,0.23161,-0.74510,0.99211,-0.88871,0.47513,0.10161,-0.64129,0.96029,-0.95336,0.62671,-0.09286,-0.46959,0.87631,-0.99725,0.79704,-0.34346};
	double y_data[DATA_LENGTH] = {0.0}; //Initialized to 0 

	int m_value = 10; // 2 ^ 10 = 1024

	double expected_x[DATA_LENGTH] = {18.14368,18.27559,18.66529,19.29429,20.13033,21.12552,22.21400,23.30963,24.30435,25.06780,25.44932,25.28332,24.39903,22.63561,19.86301,16.00821,11.08513,5.22496,-1.29827,-8.05401,-14.46169,-19.82568,-23.40505,-24.51919,-22.68285,-17.75287,-10.05781,-0.47170,9.60965,18.42342,24.13628,25.25546,21.07924,12.06688,-0.01622,-12.30422,-21.43996,-24.51199,-20.09032,-9.00552,5.51005,18.56992,25.22173,22.43273,10.69489,-5.60015,-19.52627,-24.50299,-17.59060,-1.54364,15.81379,25.16974,20.83238,4.59147,-14.37781,-24.36206,-18.45635,0.16427,19.23459,25.16095,12.97862,-8.85613,-23.64973,-19.15663,1.68657,21.70085,23.22794,4.16753,-18.52429,-23.29052,-4.80237,19.14249,23.99032,3.95513,-20.03214,-21.41051,2.10987,23.86628,17.83278,-9.45081,-24.53421,-7.81684,19.78177,21.78559,-5.21391,-24.47250,-8.49685,20.48897,20.05612,-9.84376,-24.07519,-0.06176,24.84653,10.32197,-20.51441,-16.24063,16.54747,21.44073,-10.73891,-22.86796,7.56515,24.82932,-3.85387,-24.31406,3.37600,25.29202,-2.58463,-24.28532,5.06594,24.72843,-7.17759,-22.63393,12.29852,20.95932,-16.37304,-15.43886,22.02681,9.12497,-24.21590,1.42112,24.61224,-11.38514,-17.98423,21.56419,7.47298,-24.55845,8.26502,20.45372,-20.34763,-5.37950,25.21313,-11.94965,-14.75777,24.72491,-4.28231,-19.70700,22.63495,0.53019,-21.68081,21.32242,1.99952,-21.84278,21.73651,0.10029,-20.31325,23.60181,-5.12388,-16.11137,25.33993,-13.05450,-7.73158,23.89983,-21.25970,5.21827,15.53866,-24.46448,19.25627,-0.97414,-16.18042,25.34683,-19.09766,4.36817,13.77711,-23.46614,23.51680,-11.58928,-3.60107,18.50191,-24.37523,22.49851,-11.14353,-2.25434,16.11939,-23.20777,24.86857,-18.11762,8.32360,4.77140,-14.88188,22.96986,-24.59390,22.96840,-15.75897,7.67852,2.83322,-11.03557,18.98087,-22.76955,25.36394,-23.72704,21.46681,-15.98862,11.08320,-4.17825,-1.08208,7.46672,-11.59287,16.45358,-18.89369,22.05833,-22.93190,24.72158,-24.47104,25.38269,-24.50952,25.01363,-23.93564,24.38491,-23.38528,23.99246,-23.21578,24.05912,-23.51931,24.54823,-24.12967,25.16090,-24.61096,25.32130,-24.24936,24.18879,-22.10339,20.76763,-17.19582,14.20225,-8.92727,4.31115,2.28860,-7.72517,14.37016,-18.86895,23.39600,-24.56208,24.62637,-20.55081,15.13125,-6.13261,-2.76643,12.88013,-19.88393,24.84453,-23.90242,19.29222,-9.06260,-2.32455,14.68994,-22.32550,25.19687,-19.59101,9.00682,5.91166,-18.00041,25.07064,-21.77581,10.99465,5.61189,-19.04724,25.29723,-18.81241,4.13034,13.92166,-23.94529,22.07405,-6.68800,-11.88334,24.45732,-20.85597,4.53628,15.97599,-24.72410,16.67541,4.72605,-21.90759,22.82318,-4.35524,-17.15479,24.88794,-9.84712,-13.56234,25.22728,-11.98695,-12.50550,25.22115,-11.12531,-14.28525,24.92391,-7.09948,-18.37775,23.05671,0.51049,-23.03238,17.30831,11.20733,-24.65899,5.64028,21.67782,-18.37998,-10.67316,24.77230,-1.78042,-23.58393,13.10053,18.35242,-20.20619,-10.48496,24.20799,3.17538,-24.87372,3.47573,24.39288,-8.03151,-22.84963,11.38782,21.85224,-12.89079,-21.07922,13.41262,21.39256,-12.36468,-22.16503,10.18133,23.57788,-6.26958,-24.69035,0.82491,24.88156,6.19099,-22.89516,-13.97482,17.64217,20.93581,-8.66752,-24.88632,-3.54035,22.87808,15.87348,-13.79499,-24.21068,-1.64437,22.86050,17.15778,-10.64982,-25.12452,-8.91873,17.66506,23.19956,1.97425,-21.52118,-21.64137,0.98154,22.15384,20.52848,-1.53518,-22.20235,-22.26251,-2.42241,19.06055,23.68558,8.23584,-14.01430,-25.34108,-17.58750,2.70654,20.48118,23.53378,10.46852,-9.53252,-23.65241,-23.66632,-10.27686,8.30737,21.75257,23.31690,12.84521,-3.97446,-19.03232,-25.78037,-21.86868,-9.55425,5.83948,18.39272,23.84030,20.81599,10.86672,-2.49468,-15.17031,-23.75804,-26.37094,-22.87003,-14.59009,-3.75741,7.17467,16.09020,21.57037,23.02381,20.62239,15.10981,7.55637,-0.87864,-9.13651,-16.38215,-22.06035,-25.89661,-27.85963,-28.10285,-26.90006,-24.58549,-21.50503,-17.98071,-14.28873,-10.64873,-7.22205,-4.11583,-1.39083,0.92942,2.84916,4.39189,5.59312,6.49458,7.13993,7.57171,7.82940,7.94834,7.95922,7.88806,7.75644,7.58192,7.37853,7.15726,6.92658,6.69289,6.46091,6.23402,6.01454,5.80402,5.60338,5.41306,5.23320,5.06368,4.90422,4.75441,4.61381,4.48190,4.35817,4.24210,4.13319,4.03095,3.93492,3.84467,3.75977,3.67987,3.60459,3.53362,3.46665,3.40341,3.34363,3.28709,3.23357,3.18286,3.13479,3.08918,3.04588,3.00475,2.96565,2.92847,2.89308,2.85940,2.82731,2.79674,2.76759,2.73981,2.71330,2.68802,2.66389,2.64087,2.61890,2.59792,2.57791,2.55880,2.54057,2.52318,2.50659,2.49076,2.47568,2.46131,2.44763,2.43461,2.42223,2.41047,2.39931,2.38872,2.37870,2.36922,2.36027,2.35184,2.34392,2.33649,2.32953,2.32305,2.31703,2.31146,2.30633,2.30164,2.29738,2.29354,2.29012,2.28711,2.28452,2.28232,2.28053,2.27915,2.27815,2.27756,2.27736,2.27756,2.27815,2.27915,2.28053,2.28232,2.28452,2.28711,2.29012,2.29354,2.29738,2.30164,2.30633,2.31146,2.31703,2.32305,2.32953,2.33649,2.34392,2.35184,2.36027,2.36922,2.37870,2.38872,2.39931,2.41047,2.42223,2.43461,2.44763,2.46131,2.47568,2.49076,2.50659,2.52318,2.54057,2.55880,2.57791,2.59792,2.61890,2.64087,2.66389,2.68802,2.71330,2.73981,2.76759,2.79674,2.82731,2.85940,2.89308,2.92847,2.96565,3.00475,3.04588,3.08918,3.13479,3.18286,3.23357,3.28709,3.34363,3.40341,3.46665,3.53362,3.60459,3.67987,3.75977,3.84467,3.93492,4.03095,4.13319,4.24210,4.35817,4.48190,4.61381,4.75441,4.90422,5.06368,5.23320,5.41306,5.60338,5.80402,6.01454,6.23402,6.46091,6.69289,6.92658,7.15726,7.37853,7.58192,7.75644,7.88806,7.95922,7.94834,7.82940,7.57171,7.13993,6.49458,5.59312,4.39189,2.84916,0.92942,-1.39083,-4.11583,-7.22205,-10.64873,-14.28873,-17.98071,-21.50503,-24.58549,-26.90006,-28.10285,-27.85963,-25.89661,-22.06035,-16.38215,-9.13651,-0.87864,7.55637,15.10981,20.62239,23.02381,21.57037,16.09020,7.17467,-3.75741,-14.59009,-22.87003,-26.37094,-23.75804,-15.17031,-2.49468,10.86672,20.81599,23.84030,18.39272,5.83948,-9.55425,-21.86868,-25.78037,-19.03232,-3.97446,12.84521,23.31690,21.75257,8.30737,-10.27686,-23.66632,-23.65241,-9.53252,10.46852,23.53378,20.48118,2.70654,-17.58750,-25.34108,-14.01430,8.23584,23.68558,19.06055,-2.42241,-22.26251,-22.20235,-1.53518,20.52848,22.15384,0.98154,-21.64137,-21.52118,1.97425,23.19956,17.66506,-8.91873,-25.12452,-10.64982,17.15778,22.86050,-1.64437,-24.21068,-13.79499,15.87348,22.87808,-3.54035,-24.88632,-8.66752,20.93581,17.64217,-13.97482,-22.89516,6.19099,24.88156,0.82491,-24.69035,-6.26958,23.57788,10.18133,-22.16503,-12.36468,21.39256,13.41262,-21.07922,-12.89079,21.85224,11.38782,-22.84963,-8.03151,24.39288,3.47573,-24.87372,3.17538,24.20799,-10.48496,-20.20619,18.35242,13.10053,-23.58393,-1.78042,24.77230,-10.67316,-18.37998,21.67782,5.64028,-24.65899,11.20733,17.30831,-23.03238,0.51049,23.05671,-18.37775,-7.09948,24.92391,-14.28525,-11.12531,25.22115,-12.50550,-11.98695,25.22728,-13.56234,-9.84712,24.88794,-17.15479,-4.35524,22.82318,-21.90759,4.72605,16.67541,-24.72410,15.97599,4.53628,-20.85597,24.45732,-11.88334,-6.68800,22.07405,-23.94529,13.92166,4.13034,-18.81241,25.29723,-19.04724,5.61189,10.99465,-21.77581,25.07064,-18.00041,5.91166,9.00682,-19.59101,25.19687,-22.32550,14.68994,-2.32455,-9.06260,19.29222,-23.90242,24.84453,-19.88393,12.88013,-2.76643,-6.13261,15.13125,-20.55081,24.62637,-24.56208,23.39600,-18.86895,14.37016,-7.72517,2.28860,4.31115,-8.92727,14.20225,-17.19582,20.76763,-22.10339,24.18879,-24.24936,25.32130,-24.61096,25.16090,-24.12967,24.54823,-23.51931,24.05912,-23.21578,23.99246,-23.38528,24.38491,-23.93564,25.01363,-24.50952,25.38269,-24.47104,24.72158,-22.93190,22.05833,-18.89369,16.45358,-11.59287,7.46672,-1.08208,-4.17825,11.08320,-15.98862,21.46681,-23.72704,25.36394,-22.76955,18.98087,-11.03557,2.83322,7.67852,-15.75897,22.96840,-24.59390,22.96986,-14.88188,4.77140,8.32360,-18.11762,24.86857,-23.20777,16.11939,-2.25434,-11.14353,22.49851,-24.37523,18.50191,-3.60107,-11.58928,23.51680,-23.46614,13.77711,4.36817,-19.09766,25.34683,-16.18042,-0.97414,19.25627,-24.46448,15.53866,5.21827,-21.25970,23.89983,-7.73158,-13.05450,25.33993,-16.11137,-5.12388,23.60181,-20.31325,0.10029,21.73651,-21.84278,1.99952,21.32242,-21.68081,0.53019,22.63495,-19.70700,-4.28231,24.72491,-14.75777,-11.94965,25.21313,-5.37950,-20.34763,20.45372,8.26502,-24.55845,7.47298,21.56419,-17.98423,-11.38514,24.61224,1.42112,-24.21590,9.12497,22.02681,-15.43886,-16.37304,20.95932,12.29852,-22.63393,-7.17759,24.72843,5.06594,-24.28532,-2.58463,25.29202,3.37600,-24.31406,-3.85387,24.82932,7.56515,-22.86796,-10.73891,21.44073,16.54747,-16.24063,-20.51441,10.32197,24.84653,-0.06176,-24.07519,-9.84376,20.05612,20.48897,-8.49685,-24.47250,-5.21391,21.78559,19.78177,-7.81684,-24.53421,-9.45081,17.83278,23.86628,2.10987,-21.41051,-20.03214,3.95513,23.99032,19.14249,-4.80237,-23.29052,-18.52429,4.16753,23.22794,21.70085,1.68657,-19.15663,-23.64973,-8.85613,12.97862,25.16095,19.23459,0.16427,-18.45635,-24.36206,-14.37781,4.59147,20.83238,25.16974,15.81379,-1.54364,-17.59060,-24.50299,-19.52627,-5.60015,10.69489,22.43273,25.22173,18.56992,5.51005,-9.00552,-20.09032,-24.51199,-21.43996,-12.30422,-0.01622,12.06688,21.07924,25.25546,24.13628,18.42342,9.60965,-0.47170,-10.05781,-17.75287,-22.68285,-24.51919,-23.40505,-19.82568,-14.46169,-8.05401,-1.29827,5.22496,11.08513,16.00821,19.86301,22.63561,24.39903,25.28332,25.44932,25.06780,24.30435,23.30963,22.21400,21.12552,20.13033,19.29429,18.66529,18.27559};
	double expected_y[DATA_LENGTH] = {0.00000,-0.01132,-0.09577,-0.32636,-0.77545,-1.51341,-2.60619,-4.11137,-6.07238,-8.51102,-11.41811,-14.74309,-18.38330,-22.17481,-25.88682,-29.22263,-31.83040,-33.32669,-33.33514,-31.54047,-27.75498,-21.99051,-14.52364,-5.93753,2.87936,10.79650,16.57837,19.09411,17.57711,11.88810,2.71222,-8.39034,-19.15051,-27.00426,-29.71542,-26.08115,-16.51263,-3.24775,10.00137,19.01535,20.46623,13.31714,-0.35979,-15.66896,-26.46300,-27.82440,-18.50678,-2.10870,13.94913,21.64391,16.52272,0.66792,-17.57585,-27.67987,-23.08531,-5.87536,13.48671,22.19273,13.75355,-6.56784,-24.30091,-25.81463,-9.18288,12.96867,22.48181,10.73564,-12.73399,-27.09522,-18.60275,5.50849,22.17503,14.37885,-10.63913,-26.92119,-16.45959,10.00991,22.86897,6.72766,-19.99392,-24.94545,-1.27549,21.65185,13.94464,-14.92885,-26.21392,-3.74482,21.52417,13.15816,-17.28991,-24.53243,3.10092,23.28500,3.78353,-24.63883,-15.26587,16.97999,17.51730,-15.17457,-23.93128,7.45561,22.42591,-7.05953,-26.13331,1.94123,23.35413,-4.25205,-26.25786,2.21527,23.15753,-7.34888,-25.19187,8.23863,20.65725,-15.63015,-19.82431,17.99194,11.31687,-24.73203,-5.38705,23.71857,-7.64011,-23.26300,15.67038,12.15873,-25.19292,-0.96281,22.56434,-16.14948,-15.04660,23.16706,-4.48252,-22.84058,18.73743,4.81836,-25.64517,13.72339,10.42181,-26.06472,10.60366,12.68937,-25.98731,10.32242,12.06301,-26.00683,12.95285,8.39363,-25.35796,17.77207,1.13645,-22.01004,22.68242,-9.54339,-13.37152,23.61184,-20.83053,1.44905,15.54069,-25.85412,17.80548,-2.80828,-16.49209,23.82305,-21.98818,6.53473,8.72108,-22.76264,23.84757,-18.08011,2.41777,10.91006,-22.96847,24.06385,-20.23621,7.41390,4.40279,-17.55259,22.95302,-25.37095,19.03154,-11.50714,-0.92302,10.03442,-19.79665,23.19994,-25.59345,21.52467,-17.42604,8.69775,-1.99672,-7.24182,12.77758,-19.55461,21.93369,-25.23896,24.30148,-24.62742,21.29680,-19.79433,15.27917,-13.09236,8.39243,-6.33837,2.07762,-0.60036,-2.93326,3.66963,-6.40457,6.38956,-8.35114,7.62343,-8.84860,7.43145,-7.92486,5.80230,-5.53213,2.66429,-1.59741,-2.02385,3.84542,-8.10000,10.44536,-14.96021,17.28499,-21.32670,22.70666,-25.18633,24.42798,-24.15198,20.21043,-16.47434,9.20187,-2.62892,-6.41457,13.26368,-20.61654,23.69070,-25.25968,21.17575,-15.15052,4.46968,5.71292,-16.72131,22.74261,-25.28263,20.03977,-11.00599,-2.87200,14.71605,-23.84273,23.96641,-17.41554,3.04755,11.33524,-22.98098,24.05143,-16.20770,-0.37002,15.75568,-25.06567,20.59878,-6.49821,-12.60800,23.66242,-22.18327,6.01503,13.02489,-24.96393,19.12447,-0.96933,-19.17810,24.28385,-11.87042,-11.06467,24.26895,-18.24457,-4.51947,22.58189,-21.13054,-1.02228,21.52975,-21.78703,-0.87544,22.00756,-20.62382,-4.08409,23.65064,-16.96848,-10.39207,24.75445,-9.47339,-18.46133,22.21069,2.53248,-24.62119,12.54109,16.53777,-22.73729,-4.63326,24.72054,-8.03018,-21.58208,16.94391,14.33371,-22.81378,-6.92113,24.63841,-0.51509,-24.94057,5.79536,23.47932,-10.06475,-22.45498,12.15987,21.22747,-13.45447,-21.27623,12.91671,21.57001,-11.58107,-22.96872,8.31144,24.08643,-3.86360,-25.08407,-2.62399,24.13412,9.97013,-20.81680,-17.76469,13.54820,23.40013,-2.89732,-24.80983,-9.97571,19.20787,20.86776,-6.62680,-24.98022,-9.87306,18.04463,22.67200,-1.14321,-23.41595,-17.50822,8.84831,24.92352,13.09930,-12.86892,-24.93309,-11.04044,13.92251,25.02571,12.11852,-11.90344,-24.83431,-15.66852,6.90423,23.56689,21.08107,2.17661,-18.07265,-24.66316,-13.46652,6.99335,22.61019,23.50655,9.82136,-9.47566,-22.86364,-23.11828,-10.77384,7.08464,21.22616,25.06244,17.41465,2.34410,-13.30723,-23.14387,-23.70764,-15.38193,-1.69311,12.38954,22.33220,25.41234,21.25567,11.55960,-0.72180,-12.36725,-20.73634,-24.28747,-22.71861,-16.79469,-7.98429,1.96226,11.38753,18.99123,23.96351,26.00014,25.23127,22.10171,17.23711,11.32154,5.00171,-1.17660,-6.80098,-11.59945,-15.42932,-18.25522,-20.12259,-21.13116,-21.41142,-21.10564,-20.35384,-19.28446,-18.00900,-16.61971,-15.18954,-13.77359,-12.41126,-11.12888,-9.94226,-8.85911,-7.88114,-7.00582,-6.22784,-5.54015,-4.93482,-4.40365,-3.93857,-3.53188,-3.17646,-2.86584,-2.59418,-2.35633,-2.14776,-1.96450,-1.80311,-1.66061,-1.53445,-1.42242,-1.32263,-1.23345,-1.15349,-1.08156,-1.01663,-0.95783,-0.90439,-0.85567,-0.81110,-0.77020,-0.73256,-0.69780,-0.66560,-0.63571,-0.60786,-0.58185,-0.55751,-0.53465,-0.51315,-0.49286,-0.47369,-0.45553,-0.43829,-0.42189,-0.40626,-0.39134,-0.37706,-0.36339,-0.35026,-0.33765,-0.32550,-0.31379,-0.30248,-0.29155,-0.28097,-0.27071,-0.26075,-0.25107,-0.24166,-0.23249,-0.22355,-0.21482,-0.20629,-0.19795,-0.18979,-0.18179,-0.17394,-0.16623,-0.15866,-0.15122,-0.14389,-0.13668,-0.12956,-0.12254,-0.11561,-0.10876,-0.10199,-0.09529,-0.08866,-0.08209,-0.07557,-0.06910,-0.06268,-0.05629,-0.04995,-0.04364,-0.03735,-0.03109,-0.02485,-0.01862,-0.01241,-0.00620,0.00000,0.00620,0.01241,0.01862,0.02485,0.03109,0.03735,0.04364,0.04995,0.05629,0.06268,0.06910,0.07557,0.08209,0.08866,0.09529,0.10199,0.10876,0.11561,0.12254,0.12956,0.13668,0.14389,0.15122,0.15866,0.16623,0.17394,0.18179,0.18979,0.19795,0.20629,0.21482,0.22355,0.23249,0.24166,0.25107,0.26075,0.27071,0.28097,0.29155,0.30248,0.31379,0.32550,0.33765,0.35026,0.36339,0.37706,0.39134,0.40626,0.42189,0.43829,0.45553,0.47369,0.49286,0.51315,0.53465,0.55751,0.58185,0.60786,0.63571,0.66560,0.69780,0.73256,0.77020,0.81110,0.85567,0.90439,0.95783,1.01663,1.08156,1.15349,1.23345,1.32263,1.42242,1.53445,1.66061,1.80311,1.96450,2.14776,2.35633,2.59418,2.86584,3.17646,3.53188,3.93857,4.40365,4.93482,5.54015,6.22784,7.00582,7.88114,8.85911,9.94226,11.12888,12.41126,13.77359,15.18954,16.61971,18.00900,19.28446,20.35384,21.10564,21.41142,21.13116,20.12259,18.25522,15.42932,11.59945,6.80098,1.17660,-5.00171,-11.32154,-17.23711,-22.10171,-25.23127,-26.00014,-23.96351,-18.99123,-11.38753,-1.96226,7.98429,16.79469,22.71861,24.28747,20.73634,12.36725,0.72180,-11.55960,-21.25567,-25.41234,-22.33220,-12.38954,1.69311,15.38193,23.70764,23.14387,13.30723,-2.34410,-17.41465,-25.06244,-21.22616,-7.08464,10.77384,23.11828,22.86364,9.47566,-9.82136,-23.50655,-22.61019,-6.99335,13.46652,24.66316,18.07265,-2.17661,-21.08107,-23.56689,-6.90423,15.66852,24.83431,11.90344,-12.11852,-25.02571,-13.92251,11.04044,24.93309,12.86892,-13.09930,-24.92352,-8.84831,17.50822,23.41595,1.14321,-22.67200,-18.04463,9.87306,24.98022,6.62680,-20.86776,-19.20787,9.97571,24.80983,2.89732,-23.40013,-13.54820,17.76469,20.81680,-9.97013,-24.13412,2.62399,25.08407,3.86360,-24.08643,-8.31144,22.96872,11.58107,-21.57001,-12.91671,21.27623,13.45447,-21.22747,-12.15987,22.45498,10.06475,-23.47932,-5.79536,24.94057,0.51509,-24.63841,6.92113,22.81378,-14.33371,-16.94391,21.58208,8.03018,-24.72054,4.63326,22.73729,-16.53777,-12.54109,24.62119,-2.53248,-22.21069,18.46133,9.47339,-24.75445,10.39207,16.96848,-23.65064,4.08409,20.62382,-22.00756,0.87544,21.78703,-21.52975,1.02228,21.13054,-22.58189,4.51947,18.24457,-24.26895,11.06467,11.87042,-24.28385,19.17810,0.96933,-19.12447,24.96393,-13.02489,-6.01503,22.18327,-23.66242,12.60800,6.49821,-20.59878,25.06567,-15.75568,0.37002,16.20770,-24.05143,22.98098,-11.33524,-3.04755,17.41554,-23.96641,23.84273,-14.71605,2.87200,11.00599,-20.03977,25.28263,-22.74261,16.72131,-5.71292,-4.46968,15.15052,-21.17575,25.25968,-23.69070,20.61654,-13.26368,6.41457,2.62892,-9.20187,16.47434,-20.21043,24.15198,-24.42798,25.18633,-22.70666,21.32670,-17.28499,14.96021,-10.44536,8.10000,-3.84542,2.02385,1.59741,-2.66429,5.53213,-5.80230,7.92486,-7.43145,8.84860,-7.62343,8.35114,-6.38956,6.40457,-3.66963,2.93326,0.60036,-2.07762,6.33837,-8.39243,13.09236,-15.27917,19.79433,-21.29680,24.62742,-24.30148,25.23896,-21.93369,19.55461,-12.77758,7.24182,1.99672,-8.69775,17.42604,-21.52467,25.59345,-23.19994,19.79665,-10.03442,0.92302,11.50714,-19.03154,25.37095,-22.95302,17.55259,-4.40279,-7.41390,20.23621,-24.06385,22.96847,-10.91006,-2.41777,18.08011,-23.84757,22.76264,-8.72108,-6.53473,21.98818,-23.82305,16.49209,2.80828,-17.80548,25.85412,-15.54069,-1.44905,20.83053,-23.61184,13.37152,9.54339,-22.68242,22.01004,-1.13645,-17.77207,25.35796,-8.39363,-12.95285,26.00683,-12.06301,-10.32242,25.98731,-12.68937,-10.60366,26.06472,-10.42181,-13.72339,25.64517,-4.81836,-18.73743,22.84058,4.48252,-23.16706,15.04660,16.14948,-22.56434,0.96281,25.19292,-12.15873,-15.67038,23.26300,7.64011,-23.71857,5.38705,24.73203,-11.31687,-17.99194,19.82431,15.63015,-20.65725,-8.23863,25.19187,7.34888,-23.15753,-2.21527,26.25786,4.25205,-23.35413,-1.94123,26.13331,7.05953,-22.42591,-7.45561,23.93128,15.17457,-17.51730,-16.97999,15.26587,24.63883,-3.78353,-23.28500,-3.10092,24.53243,17.28991,-13.15816,-21.52417,3.74482,26.21392,14.92885,-13.94464,-21.65185,1.27549,24.94545,19.99392,-6.72766,-22.86897,-10.00991,16.45959,26.92119,10.63913,-14.37885,-22.17503,-5.50849,18.60275,27.09522,12.73399,-10.73564,-22.48181,-12.96867,9.18288,25.81463,24.30091,6.56784,-13.75355,-22.19273,-13.48671,5.87536,23.08531,27.67987,17.57585,-0.66792,-16.52272,-21.64391,-13.94913,2.10870,18.50678,27.82440,26.46300,15.66896,0.35979,-13.31714,-20.46623,-19.01535,-10.00137,3.24775,16.51263,26.08115,29.71542,27.00426,19.15051,8.39034,-2.71222,-11.88810,-17.57711,-19.09411,-16.57837,-10.79650,-2.87936,5.93753,14.52364,21.99051,27.75498,31.54047,33.33514,33.32669,31.83040,29.22263,25.88682,22.17481,18.38330,14.74309,11.41811,8.51102,6.07238,4.11137,2.60619,1.51341,0.77545,0.32636,0.09577,0.01132};

	fft_dif(x_data, y_data, (int) DATA_LENGTH, m_value);

	float epsilon = 0.00025;

    int pass_1 = check_if_equal(x_data, y_data, expected_x, expected_y, DATA_LENGTH, epsilon);

    double new_x_data[DATA_LENGTH] = {1.00000,1.00000,0.99999,0.99994,0.99980,0.99951,0.99898,0.99810,0.99677,0.99482,0.99211,0.98846,0.98367,0.97753,0.96982,0.96029,0.94870,0.93478,0.91825,0.89886,0.87631,0.85033,0.82067,0.78706,0.74928,0.70711,0.66037,0.60893,0.55269,0.49163,0.42578,0.35524,0.28020,0.20094,0.11785,0.03141,-0.05777,-0.14898,-0.24138,-0.33400,-0.42578,-0.51552,-0.60193,-0.68363,-0.75918,-0.82708,-0.88582,-0.93388,-0.96982,-0.99227,-1.00000,-0.99196,-0.96732,-0.92555,-0.86644,-0.79016,-0.69727,-0.58880,-0.46626,-0.33163,-0.18738,-0.03643,0.11785,0.27174,0.42123,0.56208,0.69002,0.80082,0.89044,0.95524,0.99211,0.99867,0.97339,0.91575,0.82637,0.70711,0.56104,0.39253,0.20709,0.01131,-0.18738,-0.38094,-0.56104,-0.71944,-0.84834,-0.94088,-0.99147,-0.99624,-0.95336,-0.86329,-0.72897,-0.55583,-0.35171,-0.12658,0.10786,0.33874,0.55269,0.73666,0.87872,0.96889,1.00000,0.96827,0.87387,0.72118,0.51874,0.27899,0.01759,-0.24747,-0.49710,-0.71242,-0.87631,-0.97481,-0.99847,-0.94341,-0.81196,-0.61291,-0.36110,-0.07658,0.21692,0.49382,0.72897,0.89995,0.98939,0.98689,0.89044,0.70711,0.45287,0.15147,-0.16759,-0.47181,-0.72897,-0.91063,-0.99544,-0.97193,-0.84026,-0.61291,-0.31379,0.02387,0.36110,0.65753,0.87631,0.98884,0.97884,0.84500,0.60193,0.27899,-0.08284,-0.43599,-0.73240,-0.93024,-1.00000,-0.92931,-0.72552,-0.41552,-0.04271,0.33874,0.67162,0.90429,0.99898,0.93830,0.72897,0.40176,0.00754,-0.39022,-0.72552,-0.94088,-0.99752,-0.88288,-0.61390,-0.23528,0.18738,0.57860,0.86644,0.99602,0.94045,0.70711,0.33756,-0.09911,-0.51874,-0.83821,-0.99211,-0.94669,-0.70799,-0.32213,0.13281,0.56208,0.87387,0.99924,0.90801,0.61687,0.18738,-0.28622,-0.69727,-0.95067,-0.98543,-0.79016,-0.40750,0.07407,0.54006,0.87691,1.00000,0.87570,0.53158,0.05150,-0.44388,-0.82708,-0.99677,-0.90536,-0.57346,-0.08660,0.42578,0.82424,0.99752,0.89440,0.54006,0.03141,-0.48835,-0.86956,-0.99955,-0.83684,-0.42578,0.11410,0.62180,0.94257,0.97564,0.70711,0.21692,-0.34346,-0.79704,-0.99725,-0.87631,-0.46959,0.09286,0.62671,0.95336,0.96029,0.64129,0.10161,-0.47513,-0.88871,-0.99211,-0.74510,-0.23161,0.36696,0.83477,0.99951,0.79704,0.29824,-0.31379,-0.80975,-1.00000,-0.80828,-0.30423,0.31975,0.82067,0.99951,0.78161,0.24991,-0.38442,-0.86456,-0.99211,-0.71065,-0.13281,0.50254,0.92791,0.96029,0.58167,-0.04899,-0.66037,-0.98478,-0.87631,-0.37862,0.28983,0.82990,0.99544,0.70711,0.09286,-0.56623,-0.96339,-0.90958,-0.42578,0.26205,0.82637,0.99375,0.67903,0.03141,-0.63354,-0.98648,-0.84834,-0.28381,0.42578,0.92072,0.94547,0.48285,-0.23161,-0.82708,-0.98939,-0.62867,0.06781,0.72983,1.00000,0.72811,0.05777,-0.64610,-0.99443,-0.79016,-0.14277,0.58677,0.98543,0.82282,0.18738,-0.55792,-0.98085,-0.83130,-0.19232,0.56208,0.98367,0.81706,0.15768,-0.59891,-0.99211,-0.77767,-0.08284,0.66507,0.99955,0.70711,-0.03267,-0.75343,-0.99443,-0.59690,0.18738,0.85165,0.96064,0.43825,-0.37512,-0.94088,-0.87872,-0.22550,0.58167,0.99508,0.72897,-0.03895,-0.78161,-0.98252,-0.49710,0.33874,0.93699,0.87080,0.18244,-0.63839,-1.00000,-0.63646,0.19232,0.88170,0.92219,0.27899,-0.57346,-0.99795,-0.67162,0.16388,0.87631,0.91974,0.25599,-0.60693,-0.99999,-0.61291,0.25599,0.92460,0.86138,0.11161,-0.72897,-0.98434,-0.44388,0.45846,0.98788,0.70711,-0.15768,-0.89328,-0.88582,-0.13655,0.72897,0.97960,0.39830,-0.52410,-0.99847,-0.61291,0.30423,0.95816,0.77530,-0.08910,-0.87631,-0.88756,-0.10786,0.76971,0.95635,0.27899,-0.65279,-0.99063,-0.42123,0.53689,1.00000,0.53477,-0.43032,-0.99347,-0.62180,0.33874,0.97884,0.68546,-0.26569,-0.96237,-0.72897,0.21324,0.94870,0.75508,-0.18244,-0.94088,-0.76569,0.17379,0.94045,0.76163,-0.18738,-0.94750,-0.74258,0.22305,0.96064,0.70711,-0.28020,-0.97700,-0.65279,0.35759,0.99211,0.57655,-0.45287,-0.99990,-0.47513,0.56208,0.99273,0.34582,-0.67903,-0.96168,-0.18738,0.79475,0.89720,0.00126,-0.89720,-0.79016,0.20709,0.97133,0.63354,-0.42692,-1.00000,-0.42464,0.64129,0.96571,0.16759,-0.82708,-0.85362,0.12409,0.95635,0.65564,-0.42578,-0.99965,-0.37512,0.70176,0.93162,0.03141,-0.90801,-0.73836,0.33756,0.99880,0.42578,-0.67626,-0.93699,-0.02639,0.91825,0.70711,-0.39830,-0.99934,-0.32808,0.76326,0.87631,-0.13903,-0.97564,-0.54745,0.59387,0.96029,0.06781,-0.91473,-0.69002,0.44951,0.99211,0.21078,-0.85362,-0.77131,0.35171,0.99951,0.28983,-0.81561,-0.80605,0.31021,1.00000,0.30782,-0.81196,-0.80232,0.32808,0.99951,0.26569,-0.84365,-0.75918,0.40406,0.99211,0.16140,-0.90159,-0.66695,0.53158,0.96029,-0.00754,-0.96505,-0.51012,0.69456,0.87631,-0.23772,-0.99980,-0.27416,0.86138,0.70711,-0.51012,-0.95888,0.04271,0.98011,0.42578,-0.77925,-0.79092,0.41323,0.98085,0.03141,-0.96732,-0.46070,0.76569,0.79323,-0.42578,-0.97424,0.01759,0.98205,0.38442,-0.82708,-0.71506,0.54534,0.92791,-0.18862,-1.00000,-0.18615,0.93162,0.52624,-0.74258,-0.79016,0.46626,0.95144,-0.14277,-0.99971,-0.18738,0.93917,0.48835,-0.78551,-0.73240,0.56208,0.90159,-0.29584,-0.98788,0.01382,0.99211,0.25963,-0.92219,-0.50471,0.79092,0.70711,-0.61390,-0.85817,0.40750,0.95449,-0.18738,-0.99706,-0.03267,0.99029,0.24138,-0.94088,-0.43032,0.85688,0.59387,-0.74678,-0.72897,0.61885,0.83477,-0.48065,-0.91218,0.33874,0.96339,-0.19848,-0.99147,0.06404,1.00000,0.06154,-0.99273,-0.17626,0.97339,0.27899,-0.94547,-0.36929,0.91218,0.44726,-0.87631,-0.51336,0.84026,0.56830,-0.80605,-0.61291,0.77530,0.64801,-0.74928,-0.67441,0.72897,0.69275,-0.71506,-0.70354,0.70799,0.70711,-0.70799,-0.70354,0.71506,0.69275,-0.72897,-0.67441,0.74928,0.64801,-0.77530,-0.61291,0.80605,0.56830,-0.84026,-0.51336,0.87631,0.44726,-0.91218,-0.36929,0.94547,0.27899,-0.97339,-0.17626,0.99273,0.06154,-1.00000,0.06404,0.99147,-0.19848,-0.96339,0.33874,0.91218,-0.48065,-0.83477,0.61885,0.72897,-0.74678,-0.59387,0.85688,0.43032,-0.94088,-0.24138,0.99029,0.03267,-0.99706,0.18738,0.95449,-0.40750,-0.85817,0.61390,0.70711,-0.79092,-0.50471,0.92219,0.25963,-0.99211,0.01382,0.98788,-0.29584,-0.90159,0.56208,0.73240,-0.78551,-0.48835,0.93917,0.18738,-0.99971,0.14277,0.95144,-0.46626,-0.79016,0.74258,0.52624,-0.93162,-0.18615,1.00000,-0.18862,-0.92791,0.54534,0.71506,-0.82708,-0.38442,0.98205,-0.01759,-0.97424,0.42578,0.79323,-0.76569,-0.46070,0.96732,0.03141,-0.98085,0.41323,0.79092,-0.77925,-0.42578,0.98011,-0.04271,-0.95888,0.51012,0.70711,-0.86138,-0.27416,0.99980,-0.23772,-0.87631,0.69456,0.51012,-0.96505,0.00754,0.96029,-0.53158,-0.66695,0.90159,0.16140,-0.99211,0.40406,0.75918,-0.84365,-0.26569,0.99951,-0.32808,-0.80232,0.81196,0.30782,-1.00000,0.31021,0.80605,-0.81561,-0.28983,0.99951,-0.35171,-0.77131,0.85362,0.21078,-0.99211,0.44951,0.69002,-0.91473,-0.06781,0.96029,-0.59387,-0.54745,0.97564,-0.13903,-0.87631,0.76326,0.32808,-0.99934,0.39830,0.70711,-0.91825,-0.02639,0.93699,-0.67626,-0.42578,0.99880,-0.33756,-0.73836,0.90801,0.03141,-0.93162,0.70176,0.37512,-0.99965,0.42578,0.65564,-0.95635,0.12409,0.85362,-0.82708,-0.16759,0.96571,-0.64129,-0.42464,1.00000,-0.42692,-0.63354,0.97133,-0.20709,-0.79016,0.89720,0.00126,-0.89720,0.79475,0.18738,-0.96168,0.67903,0.34582,-0.99273,0.56208,0.47513,-0.99990,0.45287,0.57655,-0.99211,0.35759,0.65279,-0.97700,0.28020,0.70711,-0.96064,0.22305,0.74258,-0.94750,0.18738,0.76163,-0.94045,0.17379,0.76569,-0.94088,0.18244,0.75508,-0.94870,0.21324,0.72897,-0.96237,0.26569,0.68546,-0.97884,0.33874,0.62180,-0.99347,0.43032,0.53477,-1.00000,0.53689,0.42123,-0.99063,0.65279,0.27899,-0.95635,0.76971,0.10786,-0.88756,0.87631,-0.08910,-0.77530,0.95816,-0.30423,-0.61291,0.99847,-0.52410,-0.39830,0.97960,-0.72897,-0.13655,0.88582,-0.89328,0.15768,0.70711,-0.98788,0.45846,0.44388,-0.98434,0.72897,0.11161,-0.86138,0.92460,-0.25599,-0.61291,0.99999,-0.60693,-0.25599,0.91974,-0.87631,0.16388,0.67162,-0.99795,0.57346,0.27899,-0.92219,0.88170,-0.19232,-0.63646,1.00000,-0.63839,-0.18244,0.87080,-0.93699,0.33874,0.49710,-0.98252,0.78161,-0.03895,-0.72897,0.99508,-0.58167,-0.22550,0.87872,-0.94088,0.37512,0.43825,-0.96064,0.85165,-0.18738,-0.59690,0.99443,-0.75343,0.03267,0.70711,-0.99955,0.66507,0.08284,-0.77767,0.99211,-0.59891,-0.15768,0.81706,-0.98367,0.56208,0.19232,-0.83130,0.98085,-0.55792,-0.18738,0.82282,-0.98543,0.58677,0.14277,-0.79016,0.99443,-0.64610,-0.05777,0.72811,-1.00000,0.72983,-0.06781,-0.62867,0.98939,-0.82708,0.23161,0.48285,-0.94547,0.92072,-0.42578,-0.28381,0.84834,-0.98648,0.63354,0.03141,-0.67903,0.99375,-0.82637,0.26205,0.42578,-0.90958,0.96339,-0.56623,-0.09286,0.70711,-0.99544,0.82990,-0.28983,-0.37862,0.87631,-0.98478,0.66037,-0.04899,-0.58167,0.96029,-0.92791,0.50254,0.13281,-0.71065,0.99211,-0.86456,0.38442,0.24991,-0.78161,0.99951,-0.82067,0.31975,0.30423,-0.80828,1.00000,-0.80975,0.31379,0.29824,-0.79704,0.99951,-0.83477,0.36696,0.23161,-0.74510,0.99211,-0.88871,0.47513,0.10161,-0.64129,0.96029,-0.95336,0.62671,-0.09286,-0.46959,0.87631,-0.99725,0.79704,-0.34346};
	double new_y_data[DATA_LENGTH] = {0.0}; //Initialized to 0

	fft_dit(new_x_data, new_y_data, (int) DATA_LENGTH, m_value);

	int pass_2 = check_if_equal(new_x_data, new_y_data, expected_x, expected_y, DATA_LENGTH, epsilon);

    if (pass_1 && pass_2) {
        printf("Test Passed!\n");
    }
    else {
        printf("Test failed.... :(\n");
    }

    return 0;
}