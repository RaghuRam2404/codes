#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define s(a) scanf("%d",&a)
#define p(a) printf("%d\n",a)
#define sll(a) scanf("%lld", &a)
#define pll(a) printf("%lld\n", a)
#define ss(a) scanf("%llu", &a)
#define pp(a) printf("%llu\n", a)
#define sstring(a) scanf("%s", a)


static ull ans[] = {2,3,14,40,84,153,250,386,566,803,1090,1450,1872,2383,2976,3684,4454,5379,6398,7572,8838,10275,11866,13620,15546,17643,19908,22428,25070,28003,31128,34506,38058,41949,46024,50472,55084,60037,65258,70868,76714,82907,89456,96338,103586,111183,119080,127584,136254,145537,154980,165040,175462,186375,197768,209568,221766,234631,247794,261724,276042,290739,306144,322110,338530,355645,373212,391626,410108,429615,449802,470584,491788,513869,536424,559924,583702,608627,634062,660178,687040,714627,743096,772250,802274,832899,864256,896870,929690,964021,998754,1034360,1070962,1108215,1146560,1185858,1225948,1267155,1308742,1352066,1395664,1440615,1486284,1533378,1580982,1629993,1679534,1730728,1782424,1835461,1889544,1944778,2000982,2058351,2116876,2176454,2236962,2298811,2361936,2426288,2491856,2558457,2626022,2695238,2765324,2836969,2909792,2984156,3058896,3136075,3213654,3293102,3373636,3455489,3538728,3623600,3709310,3797233,3885708,3976040,4067778,4160475,4255158,4351696,4448944,4548077,4648126,4750342,4853698,4958789,5065548,5173590,5283220,5394487,5507802,5622262,5737930,5856035,5974936,6096936,6218720,6343863,6469926,6597596,6726982,6858289,6991050,7126380,7262688,7401325,7541248,7683424,7826746,7972219,8120192,8269412,8420014,8573427,8727598,8885356,9044192,9204423,9367192,9531894,9698512,9866693,10037050,10210304,10384454,10560969,10739860,10920516,11103258,11288573,11474574,11664154,11854798,12049007,12243738,12441678,12641334,12843741,13047620,13254070,13462508,13673301,13886086,14102148,14318804,14539831,14762104,14986302,15212818,15442105,15673318,15908030,16144040,16383111,16623436,16867266,17113586,17361189,17612896,17865578,18121642,18379799,18640112,18904728,19169600,19438215,19708424,19983290,20258648,20537539,20819154,21103378,21388722,21677465,21970122,22265398,22562560,22862461,23165228,23470548,23778342,24089713,24403060,24720646,25037948,25361211,25685514,26013688,26344304,26677933,27014086,27353554,27694948,28041099,28388262,28739104,29092884,29449107,29809776,30172560,30538968,30907931,31278008,31654140,32031322,32413577,32797234,33184374,33574840,33968361,34364850,34764888,35167444,35573303,35982590,36396176,36811354,37230779,37652782,38078202,38506314,38938987,39373180,39814060,40255414,40700387,41149304,41601922,42056260,42515431,42978486,43443912,43911846,44385449,44861104,45341838,45824228,46310961,46800594,47293900,47791166,48292353,48796018,49305302,49815326,50330285,50849582,51371958,51897350,52428287,52960846,53498622,54039036,54582725,55131654,55683366,56239074,56798605,57361904,57929704,58500894,59075519,59653104,60236530,60821378,61413143,62007830,62605356,63207324,63812317,64422736,65037044,65654278,66277441,66901018,67533854,68165238,68804763,69446120,70092872,70742888,71397609,72054438,72718180,73384718,74055703,74730688,75410806,76094524,76782063,77473718,78170326,78869232,79574677,80283442,80997370,81715434,82437927,83163014,83894524,84629602,85368509,86112560,86861578,87613666,88371185,89131902,89898732,90669746,91443625,92224020,93008174,93795172,94590633,95386858,96190494,96996856,97807387,98625290,99445856,100271190,101101623,101935550,102776678,103617626,104468941,105323630,106181986,107044442,107912763,108784246,109663866,110544676,111432733,112324142,113222774,114124358,115030893,115941868,116858970,117779682,118706357,119637086,120576098,121515856,122463533,123413762,124371048,125332296,126299423,127270864,128246650,129227144,130216573,131208770,132204784,133209426,134215519,135229902,136247378,137269330,138298409,139332550,140373130,141413984,142464345,143519162,144580414,145646002,146716553,147794542,148875850,149959556,151054883,152150944,153256356,154364006,155479183,156597902,157723174,158855242,159990459,161129116,162279030,163431174,164591453,165754504,166925558,168100558,169278383,170466712,171659358,172857664,174061261,175267264,176485144,177705718,178932309,180164464,181403842,182644952,183896841,185149926,186415226,187679914,188953523,190232158,191516726,192806802,194105407,195407996,196714728,198029180,199348613,200678068,202009236,203348456,204693651,206042220,207400308,208761982,210133325,211507374,212888984,214273666,215668477,217067516,218474246,219885942,221303385,222727894,224161648,225596874,227041223,228488384,229945408,231407242,232873445,234349024,235831730,237320826,238813201,240312820,241822532,243331312,244853503,246380006,247911478,249450744,250996589,252548352,254107624,255671664,257244695,258820816,260409890,261997890,263599003,265202018,266814296,268431272,270054695,271687148,273326442,274971890,276625189,278281122,279945828,281620668,283297833,284983088,286677410,288373570,290081047,291793044,293515026,295242002,296974385,298714966,300464566,302217564,303980995,305748444,307524408,309305874,311095665,312891642,314697558,316507196,318327769,320151748,321982652,323819904,325667621,327523272,329381756,331251332,333127255,335010146,336897026,338796888,340701149,342610526,344531948,346454234,348390549,350332648,352279590,354233332,356195915,358167204,360146696,362130242,364125901,366122040,368135314,370148804,372168899,374198932,376239012,378282458,380336397,382394600,384467122,386539238,388624557,390713744,392816622,394918232,397033837,399155648,401284306,403421640,405564575,407717232,409882088,412049490,414223615,416409488,418601496,420798252,423007275,425220552,427448300,429673606,431915791,434163192,436417700,438681458,440951431,443229830,445516926,447812306,450117749,452427020,454746286,457073380,459406397,461752068,464105102,466465952,468831917,471206332,473592738,475981928,478387103,480797440,483212816,485638202,488072207,490514658,492964772,495422214,497891613,500366638,502850292,505342544,507844221,510353600,512872412,515393214,517931541,520470550,523029570,525584072,528157311,530732190,533318666,535912902,538513697,541127680,543746244,546373850,549011755,551657974,554312700,556977034,559648323,562329574,565022050,567717376,570429129,573140162,575867820,578598094,581339807,584093206,586853580,589624948,592400427,595186356,597986890,600788210,603604115,606423016,609255358,612095374,614948131,617803394,620674344,623551522,626434879,629330648,632235924,635145886,638069961,641004650,643941686,646891768,649849915,652822210,655796484,658784292,661782679,664780656,667800182,670821810,673856605,676897992,679952900,683015222,686084235,689161476,692254636,695350052,698461647,701574960,704704324,707841200,710989203,714145262,717312206,720483118,723665861,726860538,730068352,733280232,736504689,739734698,742976374,746228818,749489933,752761534,756043226,759334064,762635337,765944514,769263724,772592538,775932591,779281596,782643696,786007904,789393751,792779252,796178886,799585528,803003153,806435204,809872532,813322218,816779989,820244234,823731420,827214140,830713447,834223296,837742174,841268498,844810347,848356006,851917908,855487400,859065895,862656512,866260772,869868118,873488591,877120474,880758530,884414114,888069449,891741750,895429900,899119610,902825699,906537006,910261922,913996780,917740873,921495082,925263572,929033974,932824299,936616860,940426422,944246322,948075177,951914782,955763876,959624016,963497981,967377436,971273910,975167072,979083539,983012590,986946376,990893388,994847719,998812836,1002793904,1006779586,1010781537,1014792416,1018813624,1022846032,1026890993,1030939588,1035011036,1039083884,1043168259,1047264554,1051376068,1055491190,1059627297,1063767528,1067920258,1072080776,1076256595,1080443456,1084641116,1088844192,1093068241,1097297490,1101539870,1105790072,1110052663,1114326618,1118614510,1122908772,1127219633,1131537446,1135871856,1140212198,1144566463,1148930686,1153308240,1157693058,1162093589,1166506554,1170921478,1175355516,1179795701,1184254140,1188723910,1193207290,1197696255,1202196388,1206711796,1211231030,1215769789,1220316380,1224883566,1229444906,1234031389,1238624900,1243231746,1247849716,1252476961,1257120426,1261775250,1266434024,1271113209,1275798148,1280504004,1285211732,1289929613,1294671192,1299415540,1304177972,1308947759,1313726230,1318523822,1323329128,1328149525,1332978282,1337818638,1342674194,1347540757,1352418096,1357306012,1362213854,1367126493,1372042730,1376989892,1381934914,1386904391,1391873570,1396864736,1401861578,1406875285,1411893994,1416934970,1421979966,1427041219,1432111374,1437196086,1442293234,1447404331,1452524708,1457655306,1462800616,1467961659,1473126856,1478320832,1483513402,1488718505,1493942530,1499176864,1504417278,1509676695,1514946640,1520232446,1525522456,1530830647,1536155394,1541489242,1546830794,1552192661,1557562068,1562949848,1568338240,1573753563,1579174858,1584605746,1590055510,1595514643,1600986926,1606470588,1611974308,1617486367,1623004758,1628543356,1634093736,1639657453,1645228410,1650821604,1656419866,1662029161,1667660590,1673300366,1678953966,1684625215,1690297456,1695988656,1701695868,1707413599,1713145650,1718887994,1724645430,1730420183,1736198576,1742002302,1747809588,1753629767,1759464664,1765317280,1771179850,1777056565,1782949294,1788849942,1794761562,1800690345,1806631598,1812593200,1818561428,1824545009,1830538614,1836551274,1842571660,1848607401,1854660064,1860725498,1866793922,1872887243,1878990992,1885111786,1891239694,1897385101,1903540572,1909716496,1915897242,1922100155,1928311290,1934536740,1940777268,1947029679,1953298050,1959582150,1965870846,1972184317,1978494866,1984840646,1991184830,1997552155,2003937876,2010323784,2016727276,2023146369,2029577516,2036030974,2042486234,2048961505,2055448622,2061957206,2068468468,2075004915,2081548994,2088103784,2094676600,2101261789,2107861464,2114485844,2121109684,2127753357,2134411334,2141084864,2147771710,2154468589,2161187058,2167915468,2174654358,2181413495,2188182030,2194969668,2201772400,2208584291,2215410718,2222256538,2229115234,2235987163,2242873376,2249780070,2256688224,2263619791,2270563452,2277518258,2284495728,2291481541,2298486642,2305501546,2312528988,2319579301,2326637200,2333721592,2340800660,2347909501,2355028220,2362162946,2369309842,2376478807,2383647846,2390845520,2398048560,2405277447,2412510740,2419761492,2427031472,2434307491,2441608008,2448918770,2456246740,2463591015,2470941716,2478316702,2485694742,2493102915,2500514916,2507948546,2515395986,2522858177,2530326238,2537829250,2545327596,2552848813,2560386022,2567939580,2575508644,2583088945,2590687800,2598298050,2605916188,2613562657,2621219926,2628904334,2636586636,2644291223,2652012460,2659748732,2667493356,2675260175,2683041120,2690835368,2698643172,2706478521,2714317176,2722174118,2730046754,2737943075,2745842406,2753765120,2761690016,2769649917,2777613458,2785595432,2793593742,2801600159,2809634904,2817677252,2825748052,2833818435,2841906216,2850016640,2858138432,2866275269,2874431690,2882606458,2890791062,2898992589,2907205254,2915444788,2923687854,2931951879,2940232182,2948537160,2956850884,2965178901,2973522482,2981885606,2990258692,2998654345,3007063684,3015492026,3023927914,3032384309,3040858904,3049354070,3057851952,3066373783,3074915530,3083466282,3092038478,3100627549,3109226196,3117844678,3126485186,3135136343,3143801106,3152486074,3161184340,3169905577,3178634284,3187386662,3196146648,3204929171,3213732474,3222549962,3231376396,3240227687,3249089406,3257974260,3266866406,3275780705,3284710842,3293663094,3302622540,3311602851,3320602064,3329618076,3338641412,3347694963,3356750690,3365837482,3374924418,3384048977,3393175562,3402322056,3411484730,3420659217,3429865818,3439078014,3448309368,3457563409,3466821104,3476105606,3485405454,3494717409,3504055386,3513400260,3522763928,3532153439,3541538492,3550969514,3560403470,3569853065,3579323254,3588810246,3598316166,3607836625,3617367612,3626922710,3636490804,3646074135,3655683116,3665310774,3674954310,3684615595,3694279514,3703976066,3713685136,3723410045,3733152400,3742919544,3752693476,3762496067,3772302338,3782135124,3791982784,3801846411,3811731330,3821634356,3831542478,3841487805,3851439338,3861413314,3871393324,3881402495,3891423942,3901474012,3911529442,3921599625,3931696504,3941810660,3951932866,3962083069,3972254530,3982429276,3992636904,4002850757,4013087438,4023337824,4033608856,4043900765,4054198736,4064534650,4074874276,4085235983,4095616290,4106011924,4116425004,4126851565,4137305588,4147778252,4158260360,4168772255,4179292832,4189837876,4200381160,4210968547,4221565430,4232176096,4242797210,4253454063,4264112868,4274808348,4285518564,4296236169,4306975478,4317738088,4328509836,4339306115,4350115544,4360959164,4371798928,4382667561,4393555696,4404464052,4415384142,4426329453,4437289830,4448268148,4459263664,4470286715,4481314626,4492372984,4503444156,4514533665,4525647114,4536765570,4547919744,4559080565,4570253976,4581464436,4592681494,4603927465,4615182866,4626461922,4637758862,4649068689,4660398040,4671757414,4683122350,4694518667,4705915198,4717351762,4728796046,4740260755,4751748948,4763250430,4774765908,4786310385,4797867300,4809451880,4821044766,4832661999,4844294982,4855953786,4867622830,4879323081,4891037598,4902762840,4914510028,4926270829,4938069832,4949882092,4961708296,4973551243,4985418526,4997302348,5009209016,5021131045,5033067984,5045037464,5057008504,5069015659,5081031882,5093076382,5105134308,5117211001,5129304178,5141431804,5153563312,5165723983,5177898598,5190080300,5202304766,5214529315,5226792872,5239068222,5251358566,5263671061,5275990290,5288362800,5300712424,5313118951,5325526082,5337957554,5350408514,5362882687,5375369872,5387874018,5400402364,5412956921,5425518828,5438115382,5450717604,5463345519,5475996290,5488669568,5501351658,5514063045,5526789580,5539543668,5552306658,5565098991,5577905126,5590733412,5603584100,5616444003,5629336848,5642248534,5655168196,5668125085,5681093300,5694085560,5707096550,5720122599,5733165732,5746239638,5759327764,5772447423,5785575876,5798731676,5811891310,5825087149,5838300884,5851539016,5864784200,5878058691,5891355222,5904674546,5917997550,5931363839,5944734320,5958128952,5971542328,5984990335,5998441434,6011921054,6025419976,6038939353,6052481726,6066039752,6079624540,6093228895,6106852630,6120491910,6134165566,6147838345,6161547778,6175275848,6189027080,6202799681,6216576224,6230394786,6244221106,6258071869,6271949788,6285840580,6299756962,6313688795,6327638104,6341627114,6355624520,6369649417,6383684480,6397753286,6411830688,6425929381,6440059480,6454206402,6468366906,6482545975,6496761462,6510997348,6525251058,6539528145,6553818860,6568134536,6582470430,6596830531,6611207938,6625616746,6640020582,6654475471,6668931770,6683428920,6697931510,6712460681,6727005792,6741583698,6756164900,6770800851,6785419986,6800087824,6814762720,6829458547,6844182304,6858938020,6873703012,6888483751,6903290286,6918121526,6932968586,6947841991,6962752008,6977661724,6992596738,7007559889,7022543612,7037552900,7052571750,7067624243,7082684946,7097783250,7112889280,7128033065,7143185370,7158363314,7173565728,7188787653,7204035536,7219308772,7234592664,7249907441,7265231148,7280591166,7295963634,7311364157,7326786566,7342230716,7357688070,7373188005,7388694614,7404225390,7419779620,7435356299,7450947596,7466580654,7482223704,7497889309,7513568824,7529287974,7545010164,7560765209,7576548348,7592345416,7608171978,7624012699,7639883798,7655771758,7671670796,7687613755,7703574436,7719551280,7735555756,7751577603,7767626184,7783701014,7799791488,7815892625,7832035416,7848205494,7864369726,7880591689,7896816482,7913066490,7929340632,7945629983,7961951980,7978289098,7994660654,8011046883,8027447652,8043893424,8060356642,8076830587,8093328966,8109853738,8126400276,8142977903,8159552794,8176191192,8192820370,8209485199,8226165042,8242877342,8259609718,8276371747,8293147314,8309948116,8326766176,8343613785,8360484078,8377374156,8394299830,8411241507,8428197558,8445183102,8462195282,8479237165,8496288434,8513374120,8530469312,8547604315,8564753568,8581923012,8599115324,8616343285,8633586176,8650852780,8668140722,8685457649,8702789556,8720161318,8737536540,8754936697,8772377736,8789843310,8807313422,8824823213,8842341766,8859903884,8877470058,8895065153,8912692712,8930332972,8947997016,8965695163,8983403768,9001150928,9018912064,9036703693,9054507592,9072355708,9090204302,9108098339,9126002432,9143933108,9161886930,9179861271,9197856948,9215897160,9233943114,9252022641,9270119342,9288248306,9306391146,9324557643,9342761462,9360978742,9379215986,9397490989,9415778226,9434091550,9452440360,9470802395,9489198354,9507607876,9526046338,9544508993,9562993818,9581504968,9600031880,9618590625,9637180752,9655789640,9674416678,9693087719,9711759562,9730472420,9749182814,9767951517,9786730938,9805540422,9824368064,9843220397,9862093394,9880999472,9899929048,9918876253,9937852414,9956859370,9975870632,9994934387,10014015638,10033105882,10052227770,10071373693,10090553898,10109762104,10128977488,10148231189,10167498432,10186810792,10206119316,10225469367,10244845262,10264241622,10283666732,10303115955,10322590558,10342093734,10361610594,10381161481,10400724618,10420336514,10439958834,10459603921,10479279632,10498975164,10518701320,10538435055,10558217442,10578024970,10597856856,10617695815,10637580834,10657486038,10677408894,10697360693,10717324448,10737351984,10757356452,10777415937,10797490606,10817604126,10837729902,10857884481,10878062656,10898275508,10918495414,10938760279,10959038096,10979350698,10999671710,11020042107,11040434500,11060839024,11081279524,11101742005,11122212182,11142732576,11163270756,11183847511,11204434214,11225042838,11245682628,11266356085,11287047216,11307767766,11328515634,11349284329,11370078840,11390909038,11411757060,11432633625,11453524504,11474457982,11495406374,11516382039,11537387832,11558437312,11579481584,11600567009,11621677720,11642809122,11663968734,11685154123,11706369818,11727610112,11748874370,11770169025,11791481848,11812835868,11834205196,11855604117,11877021602,11898480964,11919946216,11941449345,11962979462,11984542348,12006106786,12027724211,12049365552,12071020970,12092711898,12114427243,12136167448,12157939146,12179715414,12201549343,12223390254,12245254860,12267170654,12289093437,12311038676,12333020386,12355033114,12377070053,12399113920,12421217294,12443322570,12465471527,12487633636,12509823728,12532050536,12554284467,12576564182,12598867000,12621198120,12643564045,12665922368,12688346202,12710767806,12733238915,12755725032,12778244868,12800787392,12823360167,12845963668,12868589540,12891236610,12913910157,12936622528,12959350566,12982115700,13004901871,13027714310,13050571368,13073409582,13096311267,13119236968,13142204514,13165173320,13188185329,13211213948,13234281326,13257366628,13280475275,13303620722,13326796268,13349987696,13373215269,13396452730,13419746066,13443059682,13466384479,13489741518,13513143516,13536543354,13560008027,13583472408,13606965138,13630499308,13654051047,13677635522,13701241980,13724885486,13748557857,13772248716,13795972374,13819715814,13843497277,13867303114,13891137032,13914980616,13938883585,13962791824,13986744736,14010713654,14034716899,14058745986,14082810142,14106888102,14130994299,14155133356,14179305726,14203498440,14227722875,14251969756,14276262914,14300564754,14324904103,14349258448,14373668872,14398081960,14422531757,14447014884,14471511074,14496049332,14520606577,14545181106,14569822372,14594473296,14619142081,14643853518,14668576608,14693342268,14718139465,14742940602,14767798618,14792654642,14817561397,14842496844,14867463848,14892450960,14917471153,14942518848,14967584980,14992687908,15017821485,15042986304,15068173328,15093386154,15118628109,15143919496,15169207610,15194550226,15219901835,15245279576,15270710138,15296144696,15321640349,15347145864,15372680834,15398244486,15423824559,15449456526,15475103438,15500769300,15526490375,15552217560,15577998438,15603777750,15629594133,15655461502,15681342292,15707241014,15733192061,15759150356,15785171058,15811173434,15837240727,15863319832,15889437080,15915584654,15941762089,15967963440,15994186298,16020444676,16046731979,16073057950,16099406314,16125789234,16152201283,16178631664,16205102002,16231584268,16258127913,16284679134,16311264060,16337862544,16364520555,16391194382,16417884346,16444623944,16471382191,16498165418,16525006026,16551838476,16578736769,16605626976,16632576154,16659553820,16686536249,16713563480,16740635126,16767724490,16794830823,16821974702,16849169336,16876361978,16903611681,16930870118,16958175992,16985496554,17012854353,17040233592,17067652688,17095109400,17122584275,17150073450,17177626388,17205191562,17232786887,17260409574,17288085032,17315752620,17343474543,17371215520,17399012792,17426807490,17454649443,17482515950,17510410802,17538333408,17566302083,17594295500,17622306446,17650348094,17678435759,17706542100,17734689766,17762866864,17791067643,17819296882,17847552616,17875852128,17904174837,17932537694,17960919754,17989333126,18017772357,18046250578,18074762760,18103293176,18131868469,18160456804,18189098918,18217739816,18246441935,18275161050,18303920864,18332689100,18361515701,18390363596,18419238348,18448151842,18477074797,18506044394,18535051494,18564061894,18593137943,18622237954,18651342440,18680491600,18709672969,18738899498,18768140962,18797425786,18826746031,18856073390,18885447670,18914845944,18944272731,18973738798,19003230552,19032762076,19062317279,19091900810,19121538842,19151170524,19180862109,19210568922,19240320890,19270094376,19299911157,19329733160,19359617928,19389506564,19419432221,19449405536,19479404784,19509440906,19539491137,19569573982,19599698162,19629859524,19660031333,19690249910,19720514094,19750756338,19781098013,19811430718,19841812980,19872205948,19902643885,19933125064,19963633374,19994146748,20024721529,20055313338,20085932250,20116592238,20147279255,20178022252,20208770688,20239553276,20270377811,20301213748,20332106250,20363009354,20393971129,20424940572,20455966556,20487002944,20518083479,20549166250,20580314610,20611486186,20642684793,20673917696,20705198884,20736490166,20767828775,20799186792,20830586444,20862006010,20893455653,20924941858,20956490824,20988043646,21019618253,21051254198,21082901832,21114590116,21146312149,21178063062,21209847796,21241651490,21273502487,21305376274,21337298660,21369241572,21401229309,21433229304,21465275196,21497342488,21529461053,21561596426,21593774244,21625972782,21658204781,21690477120,21722791322,21755134236,21787494995,21819900796,21852332268,21884794996,21917293829,21949835594,21982401362,22014997076,22047627811,22080292384,22112983654,22145732082,22178481553,22211260186,22244107892,22276961372,22309874491,22342794190,22375751058,22408739494,22441772875,22474840086,22507927938,22541044352,22574226823,22607390636,22640638962,22673877816,22707176613,22740503326,22773868242,22807255392,22840688897,22874132348,22907639274,22941155230,22974723725,23008318596,23041938380,23075582824,23109283601,23143019188,23176759506,23210549988,23244376013,23278221962,23312132822,23346075390,23380028971,23414021622,23448046332,23482104552,23516198035,23550329758,23584492418,23618683748,23652915213,23687172732,23721468604,23755799948,23790166213,23824556474,23858999750,23893455318,23927971419,23962487240,23997062390,24031655816,24066280289,24100954938,24135660864,24170403380,24205186331,24239968344,24274818322,24309681074,24344601529,24379533656,24414513094,24449515740,24484555991,24519635520,24554752174,24589888700,24625070621,24660277174,24695534248,24730817482,24766132711,24801475002,24836864320,24872291246,24907735245,24943214780,24978757848,25014296252,25049901857,25085509512,25121194080,25156878104,25192601833,25228365148,25264172646,25299993476,25335869115,25371757406,25407699994,25443681234,25479664321,25515720536,25551788368,25587898096,25624046459,25660220942,25696438404,25732666860,25768967089,25805276888,25841634294,25878026886,25914450751,25950900990,25987388160,26023906660,26060469545,26097072514,26133686194,26170369402,26207069053,26243807710,26280587564,26317377906,26354234849,26391089666,26428015708,26464953378,26501944181,26538954468,26576007184,26613082410,26650195173,26687376724,26724565074,26761788244,26799057515,26836333388,26873686844,26911050610,26948455361,26985896032,27023375642,27060861266,27098417837,27135988870,27173625372,27211280024,27248951449,27286677938,27324447318,27362231216,27400050713,27437918672,27475822772,27513741824,27551708669,27589722646,27627773876,27665860882,27703972697,27742128040,27780311476,27818515304,27856777643,27895061562,27933404578,27971755644,28010158189,28048599426,28087062890,28125572058,28164115175,28202686988,28241306548,28279953046,28318653495,28357361818,28396135596,28434920350,28473738405,28512618302,28551526572,28590464636,28629427745,28668427450,28707494298,28746558876,28785694857,28824848456,28864042420,28903264042,28942539619,28981826562,29021176470,29060532814,29099937047,29139380408,29178880920,29218373652,29257966801,29297542282,29337155662,29376825490,29416525173,29456262780,29496040568,29535845626,29575699071,29615575834,29655490552,29695447436,29735440959,29775483640,29815532444,29855612978,29895776113,29935928748,29976170728,30016424922,30056685325,30097018850,30137384962,30177762088,30218206129,30258668962,30299189292,30339714084,30380281589,30420917598,30461574960,30502268586,30542998827,30583748004,30624553190,30665379064,30706266071,30747180872,30788140980,30829108192,30870127079,30911205442,30952292638,30993423938,31034612853,31075812784,31117073112,31158338066,31199659353,31241010488,31282423678,31323841980,31365308867,31406810016,31448360874,31489940842,31531578811,31573217138,31614919890,31656648208,31698424191,31740229186,31782061650,31823958552,31865880531,31907812334,31949823820,31991832300,32033921431,32076011204,32118160974,32160344004,32202566045,32244825404,32287110744,32329441518,32371801339,32414225676,32456673990,32499159460,32541670385,32584245188,32626822180,32669468204,32712130163,32754844502,32797598670,32840359932,32883213905,32926063860,32968971306,33011891946,33054874939,33097884290,33140944310,33184025172,33227151681,33270320982,33313530476,33356777740,33400036795,33443360570,33486722326,33530129662,33573564043,33617014266,33660536416,33704071158,33747659501,33791292496,33834944488,33878654508,33922390927,33966162492,34009976558,34053837718,34097729907,34141656110,34185651674,34229637386,34273693703,34317767380,34361910208,34406040860,34450252293,34494476232,34538786124,34583085126,34627447081,34671844434,34716288480,34760739122,34805253873,34849793072,34894393410,34939006574,34983683567,35028382316,35073109200,35117911320,35162715289,35207580130,35252483906,35297418222,35342393833,35387408278,35432477458,35477546432,35522687065,35567848898,35613069840,35658326920,35703597759,35748924646,35794304042,35839689194,35885134521,35930622098,35976144660,36021708200,36067314445,36112940546,36158641470,36204346990,36250114569,36295899346,36341736852,36387601042,36433536761,36479492902,36525475828,36571508940,36617570521,36663684288,36709841716,36756030452,36802271203};


int main(){
	//freopen("input.in", "r", stdin);
	int t, n;
	s(t);
	while(t--){
		s(n);
		pp(ans[n-3]);
	}
	return 0;
}