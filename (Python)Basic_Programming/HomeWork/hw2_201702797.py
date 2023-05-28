
def list_to_str(str_list):
    result = ""
    for s in str_list:
        result += str(s) + ""
    return result.strip()

# 소수점 아래 마지막 부터 0 제거
def delete_zero(str_list):
    for i in range(len(str_list)-1, -1, -1):
        if str_list[i] == 0:
            str_list.pop(i)
        else:
            break

# '0' 과 '.' 을 제외한 str과 진법이 입력되면 곱셈 연산 실행.
def multiple_number(list_str, n, rs):
    result = []
    carry = 0

    # 문자열로 변환된 숫자의 각 자릿수에 접근
    for i in range(len(list_str) - 1, -1, -1):
        # 한 자리수와 곱셈 연산
        product = int(list_str[i]) * n + carry
        # 현재 자릿수의 결과를 result 배열에 저장
        result.append(product % 10)
        # 다음 자릿수로 넘어갈 carry 계산
        carry = product // 10

    if carry > 0:
        # carry가 남아있다면 마지막 자릿수로 추가
        while carry > 0:
            print(f'carry = {carry}')
            rs.append(carry % 10)
            carry //= 10
    else:
        rs.append(0)

    # 결과를 역순으로 반환
    i = len(result)-1
    while i >= 0:
        result.append(result.pop(i))
        i -= 1

    return result

def convert_to_n_ary(in_str: str, to_ary: int) -> str:
    print(f"{in_str}을 {to_ary}진법으로 변환 시작:")
    # 문자열 배열로 저장
    list_str = list(in_str)
    # '0' 삭제
    list_str.pop(0)
    # '.' 삭제
    list_str.pop(0)

    rs = []
    while len(rs) != 1000:
        list_str = multiple_number(list_str, to_ary, rs)
        print(f"list_str = {list_str}")
    if rs[len(rs) - 1] == "0":
        check = 0
        # 만약 소수점 아래 가장 뒤 부터 5개 연속으로 "0" 검출 시 0 삭제
        for i in range(len(rs) - 1, len(rs) - 6, -1):
            if rs[i] == "0":
                check += 1
                print(f"check {check}")
        if check == 5:
            delete_zero(rs)
    return f"0.{list_to_str(rs)}"

def equal_str(str1, str2):
    for i in range(len(str1)):
        if str1[i] != str2[i]:
            print(f'str1[{i}] : {str1[i]} != str2[{i}] : {str2[i]}')
            return
    print('두 문자열은 같습니다!')

# final_list = list_to_str(multiple_number(list_str, to_ary))
    # if final_list[len(final_list) - 1] == "0":
    #     check = 0
    #     # 만약 소수점 아래 가장 뒤 부터 5개 연속으로 "0" 검출 시 0 삭제
    #     for i in range(len(final_list) - 1, len(final_list) - 6, -1):
    #         if final_list[i] == "0":
    #             check += 1
    #             print(f"check {check}")
    #     if check == 5:

    # # 만약 입력 문자열의 뒷 자리가 0 이라면 계산없이 0 추가 후 continue
    # if int(list_str[i]) == 0:
    #     result.append(0)
    #     continue

if __name__ == '__main__':
    # Please write here to test your function
    print(convert_to_n_ary('0.410392931183794', 4))
    equal_str("0.1221003320023121330122200332032020211320012100003022000210002210103231230100231002113002123003013310321022311031003320303002030121103322112203233030121131101130112211032210021131010103233002212132213303333231001012031123323031321110233112112110231322213323222023021312101321221020132300332111303121312322201232233113132012333113000322133121222312211332102021233331302302032033110330131123121223213310332321031101032302120031312310121032321003333001201203330020012313111331212100032101332001211231032100320332100233322203233222233113303222300030122121023003003130202122222320020031201012300321133103223210100330222312023120300321310013310302233210100233203120120202300031231131213332101221111202022100212303021302313230320120130101121131330003012123102332201113100122313200322121220103121220200020120130110301331032010120001130032021320012322001323001302012030221212233312031301110203001031021300212311120312003231232312000323213113120003301132202130202331010101020220132323202202020112020133132211330",
              "0.1221003320023121330122201010100222231131302113131200211202330102113223213213303031202320231132201132211312021121112200102303212223020020130321000121031000022022201321002202011320001220032001230301033300213303321202112013212023132111211313210230232301312003010310220130131000301031320120131113022312001223133031003033310123133110010301033222002300321012012202010203011232010232020123310022022030023330031121231222322002013131231021033032300221303220230333210212132311030101223121302230133011331012212123103133223333212132100322203010223220001122101110222000230011231202221020100103212233013122121300320020302310112023111020332023211202330201300110033022100012121223211122331303203322303112202203131330020331011323020003213103300303301202021211120220310033130022330333222333001230320333323212330231111030231113102203130222203310010232323220322203113131212102132231301132311221011000322311112122020011122113230311121022322222312002022101003130032113010330023322312230103113000233003113332000023010222031")
    # print(convert_to_n_ary('0.8125', 2))
    # print('--------------------------')
    # print(convert_to_n_ary('0.25', 8))
    # print('--------------------------')
    # print(convert_to_n_ary('0.25', 7))
    # print('--------------------------')
    # print(convert_to_n_ary('0.7', 8))
    # print('--------------------------')
    # print(convert_to_n_ary('0.5', 4))
    # print('--------------------------')
    # print(convert_to_n_ary('0.1', 2))
    # print('--------------------------')
    # print(convert_to_n_ary('0.1', 3))
    # print('--------------------------')
    # print(convert_to_n_ary('0.2', 3))
    # print('--------------------------')
    # print(convert_to_n_ary('0.45', 4))
    # print(convert_to_n_ary('0.123', 2))
    # print(convert_to_n_ary('0.97531', 9))
    # print(convert_to_n_ary('0.456', 4))
    # print(convert_to_n_ary('0.08', 7))
    # equal_str("0.0363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363",
    #           "0.0363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363036303630363")
    # print(convert_to_n_ary('0.3423213244595', 4))
    # equal_str("0.111322021132303110123212223123222001101321113013130113120312220122002130002100020201312112213233132210131313031223030302221021022132023012031310001121003330302232010121122100222032103303103331332301232201202223212232002220023012223023133331223023302202313120100300011203132031332223300000322211321230321131300303201013121300321321201101021021113300233322233113102300012012203102022023003201101321223321312202323333310132113221030103021032122011221133333323032032321011311100013200313302311201223102111102011203223132222203231212303312001101310132001330113301313112103122013212010031230233231311210033203012311133323330013313000013330300131031002210103112223322233320031230030320312201321133223131223331113133222233130031200033313110300211313113331120232302101012121101230232100302111202010101212310132313221012132323031030203330200210030123033131201033302012332013020233103301312201222301320033020120232233023202000231332332212203213133232311201100230210003300313212012301111212000102122110321002121",
    #           "0.1113220211323031101232122231232220011013211130131301131203122201220021300021000202013121122132331322101313130312230303022210210221320230120313100011210033303022320101211221002220321033031033313323012322012022232122320022200230122230231333312230233022023131201003000112031320313322233000003222113212303211313003032010131213003213212011010210211133002333222331131023000120122031020220230032011013212233213122023233333101321132210301030210321220112211333333230320323210113111000132003133023112012231021111020112032231322222032312123033120011013101320013301133013131121031220132120100312302332313112100332030123111333233300133130000133303001310310022101031122233222333200312300303203122013211332231312233311131332222331300312000333131103002113131133311202323021010121211012302321003021112020101012123101323132210121323230310302033302002100301230331312010333020123320130202331033013122012223013200330201202322330232020002313323322122032131332323112011002302100033003132120123011112120001021221103210021210")
    #
    ##### print(convert_to_n_ary('0.5674793170038910000000000000000000000000000000000000000000000000000000000000', 7))
    ##### equal_str("3654342422241642622452365020160520434414631053653451504301236330162451625424221344030263241464163132643530264025512361044312030523036520431134066544266636232304232440112260433013266245441025323402666662452435444143250256025416500002451221130121163101443060154032204365111664266545014503614054233505262111412015060130616461234243611133030645214164606662306213121006522061205305032060654045412335301503666523126604651656536554233143403144366414661632656042134415135610511003121264442034300404200533602255666155344533432446120350456426435103224424325542460036030536230454415014320404101560424651063326354513324635004615640024056661305605010413265056304134454361060041560263256543626320101060055644102401243624244414416166032461264053656116036224664160363346153642303643015216313262344005362165525113110653655525363320166514042115224366021333522605014410530505366446105116523151503413600521366343302616135326042061635411225522225145446643415506230024230232646523314322262241056205122400034606434154340642",
    #           "3654342422241642630564440501211534643005531212434312651414644465020210411261450500135364035663240666535626324532430305450405334602060133000245305024562045404301405005340351334504526222603054213044045053562606036046436065164545626500645020020004626316021406410234312145142036306063546043123526654004255560253534251040245621111365551563263402105541611254461345012555200625340601605110152533115325406464430025031144352424514523402300200605320251010214102311241130533620516331153341634144635212106252303451414531223501163311512102052116304611341502025041522033106412543206262152644606500445163352421313400301124201162523344132143602101016212256634263144252121633323105130556400464664455031243504620504263553346645262541621162450234110606144541434546662534301306106520510004020311054340351246554423100363234260262614152543130161426060405311314160635160163142521616351634233635420115222460010526041134014150566305103444366321645240635111434652462245161322203414240252662144046210504424115011321310322061230")
    # print(convert_to_n_ary("0.3323228103808310000000000000000000000000000000000000000000", 8))
    # equal_str("2521143344446354117564641702641017632333655121576370732142615415206375305466705735661542406262664100373505363422531342207176632263124270670022424757130303356532743741016555643114633372071115642723766576646326147505157317235351310137630504004325506212434422007165047441003721225025027757516026507444124513151420552261307132022145261130556534222164241577365562054663577545411636447337025706041035712215560004353670263636771445246453560415143427333067327262164230266035437500335757122646513173526744034465645472137704502100222244610031760120227053240440703457275676157500574215600641526676330021024754133213744611560314221371427361257646541633115722527132325104511255334066043600753567471170620026777122715213704675516245407012347161626664323154116040500146621011357633613175527271276322433447602771214263652534176201555555533023733462770415741721704232157236556515766577647467556244567436515712636124705124661715330572552027666524434050121071602344634736154055644472677161115440642626201275145344263447",
    #           "2521143344446354137056310316440754601647321373331526565515537203144434771417341006650604115754344041154647064520365616300155314442061664771136215575110310320535406477540454422331312074077664033144217624272560026267101206717332040343045512562115624072770714044720017361411725736376264250351573146662074367257576507501405410076450602224534027511013056272603375342354022574731735717014403431006036444465456312651615514335620670414563771347253655507072627471340235161507427754517663345362515232612531352433267360257777677045706266217657312646723502537102220652552722163550021710113637545524544535312345577707071237444702723712511612455326471446454042664450131476354452346260300037124624310477151264001302615652565314655435172616461306663725144722235516716711104175773621037373160033267117034362541161105360333112701050547063356276712516154076337410264602366744531766076137702772033216454340556172542566523364460423033507770406066670610253053620502356410430704446176663773276643545026134672152271745537207")
    # print(convert_to_n_ary("0.75824233611330729854841909188072327887530025980813503801963616029217934409322342635559811088410864277129311356323897253703998531429476728395809695211617262224031359878539445081840492500560945850628408519527153711754628261270729380553301256806296143587114040524837464354748837774071955120256472135310887964708528785328311052521204124572409592796833580236846881293737460807697159908822958138537256572736081228593948601290354803119483935569332054336567431050994969312303930726537376071005568096229225009417383829252646419895991748921149213411671518340246232581284619879287146498043590588659713430578848747321263764572024942204399405963337664", 6))
    # equal_str("4314403154313541500020232425003244442441433031312422040550032545354410510445310504501224310014135002112154034041303552101452430111515220402100410343415050040203043514431551421254234234533451040524545144350053524544244224204413532210135512545224320215542145553151531034552344010253132013312040024020344240125010204014153500545434123130352154443314514322442515432545014121431032312052233013421531453410451341114055141500230451143241435540441105115053142340121121152513200451344515022122340443432115235234134534421035004004220052232322124225011005533133323245002104110104112014214230515231342154410441204532352523043520302131450550034411351013031522113105205524351100122154410122331515211340235231205034345511330304053243203130514405522002530524452125545451144105554444253454535115504222300021240234345552041541021500321042545430243123003301413112222213351402240044424024200444310504121202433543155331204000305110502345404444144201355441102505350522545031251303542231152302435504415150445113014220353243",
    #           "4314403154313541500020232425003244442441433031312422040550032545354410510445310504501224310014135002112154034041303552101452430111515220402100410343415050040203043514431551421254234234533451040524545144350053524544244224204413532210135512545224320215542145553151531034552344010253132013312040024020344240125010204014153500545434123130352154443314514322442515432545014121431032312052233013421531453410451341114055141500230451143241435540441105115053142340121121152513200451344515022122340443432115235234134534421035004004220052232322124225011005533133323245002104110104112014214230515231342154410441204532352523043520302131450550034411351013031522113105205524351100122154410122331515211340235231205034345511330304053243203130514405522002530524452125545451144105554444253454535115504222300021240234345552041541021500321042545430243123003301413112222213351402240044424024200444310504121202433543155331204000305110502345404444144201355441102505350522545031251303542231152302435504415150445113014220353243")
    # print(convert_to_n_ary("0.3903899234958219269628796745906681342350864497704911954906615789359865007415653033741850556286886078049468455649637488039763268623413683983963741144961758386259282855998405539404660899542746491489348024607591721202961442671623353995496223235504102608144881123300154528820905780140410081760474406384327261557837769731266990778101868495508266785913270924568860214536618928299752124221590821102840709427242646305090683074213317869200371299983626080438582854302156296570794566987551565769427524026779718866052890280816007978479337005199710808559735959659371376621316077643151164242666215052064206000785986287447710263008588762429680078695826361688938819855205672969678951136095249216738394813321885217947311353303738121788624754629", 9))
    # equal_str("3455311810487001632446000170070755665518167374402134052806663637622148712611582450673884824133811011046078686786618176106467824843881181372584423570881164870231454720525322862343404368600467045786058352555678870646181883384027842324625503154640488355654171810364714446588086077113760138508121700308183681603011538281116724651180012435425788553840582215312500001734020272133362303037812822527471140205061754614441883258225822014007646165274675578624876051438721637000107116064121164205570775014250883142610345656546632560576314141826103776531506432153175532378265377183064348208778762602386617407832402867401852177768817775652447410670842182442067218254328776562862250663880288281308710223376086731826560267841136558631200065067258154513613827376558668335821756846041342360426624670027342258335114245127661821543760633363887714227666606012202525704535527286648665558734622740462651445162428813877760384851814335125345043866540225233483653761350882680008147234100687745210368503246547176168536415185775",
    #           "3455311810487001632446000170070755665518167374402134052806663637622148712611582450673884824133811011046078686786618176106467824843881181372584423570881164870231454720525322862343404368600467045786058352555678870646181883384027842324625503154640488355654171810364714446588086077113760138508121700308183681603011538281116724651180012435425788553840582215312500001734020272133362303037812822527471140205061754614441883258225822014007646165274675578624876051438721637000107116064121164205570775014250883142610345656546632560576314141826103776531506432153175532378265377183064348208778762602386617407832402867401852177768817775652447410670842182442067218254328776562862250663880288281308710223376086731826560267841136558631200065067258154513613827376558668335821756846041342360426624670027342258335114245127661821543760633363887714227666606012202525704535527286648665558734622740462651445162428813877760384851814335125345043866540225233483653761350882680008147234100687745210368503246547176168536415185775")

    ## 입력 문자열을 뒤에 000 많이 넣을 시 약간 오류가 생김 왜?