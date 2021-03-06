#include <stdio.h>
#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/FFT>
#include "matplotlib-cpp/matplotlibcpp.h"
#include <math.h>
#include "vsp.h"

namespace plt = matplotlibcpp;
using namespace Eigen;
double coeff[] = {0.0000000028	,
               0.0000000113	,
               0.0000000282	,
               0.0000000564	,
               0.0000000973	,
               0.0000001550	,
               0.0000002311	,
               0.0000003312	,
               0.0000004567	,
               0.0000006131	,
               0.0000008034	,
               0.0000010331	,
               0.0000013051	,
               0.0000016265	,
               0.0000020028	,
               0.0000024369	,
               0.0000029387	,
               0.0000035123	,
               0.0000041649	,
               0.0000049020	,
               0.0000057350	,
               0.0000066681	,
               0.0000077096	,
               0.0000088696	,
               0.0000101564	,
               0.0000115800	,
               0.0000131487	,
               0.0000148710	,
               0.0000167611	,
               0.0000188273	,
               0.0000210796	,
               0.0000235320	,
               0.0000261945	,
               0.0000290796	,
               0.0000322001	,
               0.0000355672	,
               0.0000391966	,
               0.0000431007	,
               0.0000472910	,
               0.0000517857	,
               0.0000565961	,
               0.0000617377	,
               0.0000672247	,
               0.0000730753	,
               0.0000793008	,
               0.0000859209	,
               0.0000929484	,
               0.0001004015	,
               0.0001082958	,
               0.0001166481	,
               0.0001254755	,
               0.0001347947	,
               0.0001446213	,
               0.0001549751	,
               0.0001658715	,
               0.0001773288	,
               0.0001893640	,
               0.0002019940	,
               0.0002152371	,
               0.0002291117	,
               0.0002436331	,
               0.0002588199	,
               0.0002746888	,
               0.0002912567	,
               0.0003085421	,
               0.0003265618	,
               0.0003453313	,
               0.0003648676	,
               0.0003851875	,
               0.0004063066	,
               0.0004282403	,
               0.0004510042	,
               0.0004746137	,
               0.0004990830	,
               0.0005244276	,
               0.0005506601	,
               0.0005777947	,
               0.0006058439	,
               0.0006348206	,
               0.0006647360	,
               0.0006956014	,
               0.0007274280	,
               0.0007602271	,
               0.0007940057	,
               0.0008287752	,
               0.0008645412	,
               0.0009013135	,
               0.0009390964	,
               0.0009778983	,
               0.0010177220	,
               0.0010585719	,
               0.0011004534	,
               0.0011433667	,
               0.0011873144	,
               0.0012322981	,
               0.0012783164	,
               0.0013253692	,
               0.0013734537	,
               0.0014225670	,
               0.0014727037	,
               0.0015238607	,
               0.0015760312	,
               0.0016292080	,
               0.0016833827	,
               0.0017385468	,
               0.0017946890	,
               0.0018517968	,
               0.0019098601	,
               0.0019688635	,
               0.0020287943	,
               0.0020896343	,
               0.0021513678	,
               0.0022139766	,
               0.0022774409	,
               0.0023417410	,
               0.0024068571	,
               0.0024727640	,
               0.0025394404	,
               0.0026068610	,
               0.0026750005	,
               0.0027438305	,
               0.0028133244	,
               0.0028834539	,
               0.0029541896	,
               0.0030254988	,
               0.0030973521	,
               0.0031697142	,
               0.0032425527	,
               0.0033158338	,
               0.0033895208	,
               0.0034635784	,
               0.0035379687	,
               0.0036126536	,
               0.0036875935	,
               0.0037627506	,
               0.0038380838	,
               0.0039135523	,
               0.0039891138	,
               0.0040647261	,
               0.0041403482	,
               0.0042159337	,
               0.0042914403	,
               0.0043668243	,
               0.0044420405	,
               0.0045170425	,
               0.0045917851	,
               0.0046662233	,
               0.0047403092	,
               0.0048139990	,
               0.0048872448	,
               0.0049600002	,
               0.0050322171	,
               0.0051038505	,
               0.0051748525	,
               0.0052451766	,
               0.0053147762	,
               0.0053836048	,
               0.0054516160	,
               0.0055187645	,
               0.0055850026	,
               0.0056502865	,
               0.0057145697	,
               0.0057778099	,
               0.0058399606	,
               0.0059009795	,
               0.0059608230	,
               0.0060194487	,
               0.0060768143	,
               0.0061328791	,
               0.0061876035	,
               0.0062409466	,
               0.0062928704	,
               0.0063433382	,
               0.0063923106	,
               0.0064397524	,
               0.0064856311	,
               0.0065299087	,
               0.0065725556	,
               0.0066135393	,
               0.0066528289	,
               0.0066903947	,
               0.0067262086	,
               0.0067602438	,
               0.0067924749	,
               0.0068228765	,
               0.0068514276	,
               0.0068781055	,
               0.0069028905	,
               0.0069257615	,
               0.0069467044	,
               0.0069656994	,
               0.0069827353	,
               0.0069977980	,
               0.0070108762	,
               0.0070219586	,
               0.0070310383	,
               0.0070381066	,
               0.0070431595	,
               0.0070461926	,
               0.0070472045	,
               0.0070461926	,
               0.0070431595	,
               0.0070381066	,
               0.0070310383	,
               0.0070219586	,
               0.0070108762	,
               0.0069977980	,
               0.0069827353	,
               0.0069656994	,
               0.0069467044	,
               0.0069257615	,
               0.0069028905	,
               0.0068781055	,
               0.0068514276	,
               0.0068228765	,
               0.0067924749	,
               0.0067602438	,
               0.0067262086	,
               0.0066903947	,
               0.0066528289	,
               0.0066135393	,
               0.0065725556	,
               0.0065299087	,
               0.0064856311	,
               0.0064397524	,
               0.0063923106	,
               0.0063433382	,
               0.0062928704	,
               0.0062409466	,
               0.0061876035	,
               0.0061328791	,
               0.0060768143	,
               0.0060194487	,
               0.0059608230	,
               0.0059009795	,
               0.0058399606	,
               0.0057778099	,
               0.0057145697	,
               0.0056502865	,
               0.0055850026	,
               0.0055187645	,
               0.0054516160	,
               0.0053836048	,
               0.0053147762	,
               0.0052451766	,
               0.0051748525	,
               0.0051038505	,
               0.0050322171	,
               0.0049600002	,
               0.0048872448	,
               0.0048139990	,
               0.0047403092	,
               0.0046662233	,
               0.0045917851	,
               0.0045170425	,
               0.0044420405	,
               0.0043668243	,
               0.0042914403	,
               0.0042159337	,
               0.0041403482	,
               0.0040647261	,
               0.0039891138	,
               0.0039135523	,
               0.0038380838	,
               0.0037627506	,
               0.0036875935	,
               0.0036126536	,
               0.0035379687	,
               0.0034635784	,
               0.0033895208	,
               0.0033158338	,
               0.0032425527	,
               0.0031697142	,
               0.0030973521	,
               0.0030254988	,
               0.0029541896	,
               0.0028834539	,
               0.0028133244	,
               0.0027438305	,
               0.0026750005	,
               0.0026068610	,
               0.0025394404	,
               0.0024727640	,
               0.0024068571	,
               0.0023417410	,
               0.0022774409	,
               0.0022139766	,
               0.0021513678	,
               0.0020896343	,
               0.0020287943	,
               0.0019688635	,
               0.0019098601	,
               0.0018517968	,
               0.0017946890	,
               0.0017385468	,
               0.0016833827	,
               0.0016292080	,
               0.0015760312	,
               0.0015238607	,
               0.0014727037	,
               0.0014225670	,
               0.0013734537	,
               0.0013253692	,
               0.0012783164	,
               0.0012322981	,
               0.0011873144	,
               0.0011433667	,
               0.0011004534	,
               0.0010585719	,
               0.0010177220	,
               0.0009778983	,
               0.0009390964	,
               0.0009013135	,
               0.0008645412	,
               0.0008287752	,
               0.0007940057	,
               0.0007602271	,
               0.0007274280	,
               0.0006956014	,
               0.0006647360	,
               0.0006348206	,
               0.0006058439	,
               0.0005777947	,
               0.0005506601	,
               0.0005244276	,
               0.0004990830	,
               0.0004746137	,
               0.0004510042	,
               0.0004282403	,
               0.0004063066	,
               0.0003851875	,
               0.0003648676	,
               0.0003453313	,
               0.0003265618	,
               0.0003085421	,
               0.0002912567	,
               0.0002746888	,
               0.0002588199	,
               0.0002436331	,
               0.0002291117	,
               0.0002152371	,
               0.0002019940	,
               0.0001893640	,
               0.0001773288	,
               0.0001658715	,
               0.0001549751	,
               0.0001446213	,
               0.0001347947	,
               0.0001254755	,
               0.0001166481	,
               0.0001082958	,
               0.0001004015	,
               0.0000929484	,
               0.0000859209	,
               0.0000793008	,
               0.0000730753	,
               0.0000672247	,
               0.0000617377	,
               0.0000565961	,
               0.0000517857	,
               0.0000472910	,
               0.0000431007	,
               0.0000391966	,
               0.0000355672	,
               0.0000322001	,
               0.0000290796	,
               0.0000261945	,
               0.0000235320	,
               0.0000210796	,
               0.0000188273	,
               0.0000167611	,
               0.0000148710	,
               0.0000131487	,
               0.0000115800	,
               0.0000101564	,
               0.0000088696	,
               0.0000077096	,
               0.0000066681	,
               0.0000057350	,
               0.0000049020	,
               0.0000041649	,
               0.0000035123	,
               0.0000029387	,
               0.0000024369	,
               0.0000020028	,
               0.0000016265	,
               0.0000013051	,
               0.0000010331	,
               0.0000008034	,
               0.0000006131	,
               0.0000004567	,
               0.0000003312	,
               0.0000002311	,
               0.0000001550	,
               0.0000000973	,
               0.0000000564	,
               0.0000000282	,
               0.0000000113	,
               0.0000000028	,
};

void plot_eigen(Eigen::VectorXd x, Eigen::VectorXd y, std::string style){
    std::vector<double> vec_x(x.rows()),vec_y(x.rows());
    Eigen::Map<Eigen::VectorXd>(&vec_x[0],x.rows())=x;
    Eigen::Map<Eigen::VectorXd>(&vec_y[0],y.rows())=y;
    plt::plot(vec_x,vec_y,style.c_str());
}

int main(int argc, char** argv){
    //zeroを間に挟んだカイザー窓をテストする
    plot_eigen(VectorXd::LinSpaced(800,0,799),vsp::getKaiserWindowWithZeros(800,100,400),".-r");
    plt::title("getKaiserWindowWithZeros");
    plt::show();
    return 0;
    //CLerp関数をテスト
//    MatrixXd buff4 = Eigen::ArrayXd::LinSpaced(1,0,10);
//    std::cout <<  buff4 << std::endl;
    MatrixXd start(1,3),end(1,3);
    start << 1,2,3;
    end << -6,-5,-4;
    MatrixXd cl = vsp::CLerp(start,end,100);
    VectorXd ln = ArrayXd::LinSpaced(100,0,100);
    plot_eigen(ln,cl.col(0),".-r");
    plot_eigen(ln,cl.col(1),".-g");
    plot_eigen(ln,cl.col(2),".-b");
    plt::title("CLerp");
    plt::show();
    return 0;
    //kaiser窓を表示
//    Eigen::VectorXd vector_kaiser = vsp::getKaiserWindow(400,4);
//    std::vector<double> kaiser(vector_kaiser.rows());
//    Eigen::Map<Eigen::VectorXd>(&kaiser[0],vector_kaiser.rows(),1) = vector_kaiser;
//    plt::plot(kaiser,".-r");
//    plt::title("Kaiser window");
//    plt::show();


    int L = 300;
    int N = L*2;
    double t=1;
    Eigen::FFT<double> fft;
    Eigen::VectorXd time_vec(N),time(N);
    Eigen::VectorXcd freq_vec;
    Eigen::VectorXd vec_real(N),vec_imag(N);


    //LPFを関数で生成
    freq_vec = vsp::getLPFFrequencyCoeff(3999,8,60,8);
    vec_real.resize(freq_vec.size()/2);
    vec_imag.resize(freq_vec.size()/2);
    time.resize(freq_vec.size()/2);
    for(int i=0,e=freq_vec.size()/2;i<e;++i){
        time[i] = i;
        vec_real[i] = freq_vec[i].real();
        vec_imag[i] = freq_vec[i].imag();
    }

    plot_eigen(time,vec_real,".-g");
    plot_eigen(time,vec_imag,".-b");
    plt::title("getLPFFrequancyCoeff");
    plt::show();

    return 0;

/*    for(int i=0,e=time_vec.size();i<e;++i){
        time[i] = i;
        time_vec[i] = 1.0;
        time_vec[i] += 0.5*cos(2.0*M_PI*t*(double)i/(double)N);
        time_vec[i] += 0.2*cos(2.0*M_PI*30*(double)i/(double)N);
        time_vec[i] += 0.1*cos(2.0*M_PI*7*(double)i/(double)N);
    }




    fft.fwd(freq_vec,time_vec);

    fft.inv(time_vec,freq_vec);


    for(int i=0,e=time_vec.size();i<e;++i){
        vec_real[i] = freq_vec[i].real();
        vec_imag[i] = freq_vec[i].imag();
    }
    plt::plot(time,time_vec,".-r");
    plt::show();
    plt::plot(time,vec_real,".-g");
    plt::plot(time,vec_imag,".-b");
    plt::show();*/

//フィルタ係数
//    time_vec = std::vector<double>(coeff,std::end(coeff));
    std::vector<double> coeff_vec = std::vector<double>(coeff,std::end(coeff));
    time_vec = Eigen::Map<Eigen::VectorXd>(&coeff_vec[0],coeff_vec.size());
    Eigen::VectorXd buff(time_vec.rows());
//    std::copy(time_vec.begin()+time_vec.size()/2,time_vec.end(),std::back_inserter(buff));
//    std::copy(time_vec.begin(),time_vec.begin()+time_vec.size()/2-1,std::back_inserter(buff));
    buff.block(0,0,time_vec.rows()/2,1) = time_vec.block(time_vec.rows()/2,0,time_vec.rows()/2,1);
    buff.block(time_vec.rows()/2,0,time_vec.rows()-time_vec.rows()/2,1) = time_vec.block(0,0,time_vec.rows()-time_vec.rows()/2,1);
    time_vec = buff;
//    time_vec.resize(time_vec.size());
    vec_real.resize(time_vec.size());
    vec_imag.resize(time_vec.size());
    time.resize(time_vec.size());
    fft.fwd(freq_vec,time_vec);
    fft.inv(time_vec,freq_vec);
    for(int i=0,e=time_vec.size();i<e;++i){
        time[i] = i;
        vec_real[i] = freq_vec[i].real();
        vec_imag[i] = freq_vec[i].imag();
    }
    plot_eigen(time,time_vec,".-r");
    plt::title("filter coeff");
    plt::show();
    plot_eigen(time,vec_real,".-g");
    plot_eigen(time,vec_imag,".-b");
    plt::title("filter coeff");
    plt::show();


    //波形を自分の手で変えてみる
/*    for(int i=0,e=freq_vec.size();i<e;++i){
        freq_vec[i].real(0);
        freq_vec[i].imag(0);
    }
    freq_vec[0].real(1.0);
    freq_vec[1].real(-0.4);

    //inv
    fft.inv(time_vec,freq_vec);
    for(int i=0,e=time_vec.size();i<e;++i){
        time[i] = i;
        vec_real[i] = freq_vec[i].real();
        vec_imag[i] = freq_vec[i].imag();
    }
    plt::plot(time,time_vec,".-r");
    plt::show();
    plt::plot(time,vec_real,".-g");
    plt::plot(time,vec_imag,".-b");
    plt::show();*/

    //LPFを自分で設計
    time_vec = Eigen::VectorXd::Zero(3265);//std::vector<double>(3265,pow(10,-200.0/20.0));
    vec_real.resize(time_vec.size());
    vec_imag.resize(time_vec.size());
    freq_vec.resize(time_vec.size());
    time.resize(time_vec.size());


//    for(auto &el:freq_vec){
//        el.imag(0.0);
//        el.real(0.0);
//    }
    freq_vec = Eigen::VectorXcd::Zero(3265);

    for(int i=0,e=2;i<e;++i){
//        time_vec[i] = 1.0;
//        time_vec[time_vec.size()-1-i] = 1.0;
        freq_vec[i].real(1.0);
        freq_vec[time_vec.size()-1-i].real(1.0);
    }



//    fft.fwd(freq_vec,time_vec);
    fft.inv(time_vec,freq_vec);
    for(int i=0,e=time_vec.size();i<e;++i){
        time[i] = i;
        vec_real[i] = freq_vec[i].real();
        vec_imag[i] = freq_vec[i].imag();
    }
//    for(int i=0,e=time_vec.size();i<e;++i){
//        time[i] = i;
//    }
    plot_eigen(time,time_vec,".-r");
    plt::title("DIY filter coeff");
    plt::show();
    plot_eigen(time,vec_real,".-g");
    plot_eigen(time,vec_imag,".-b");
    plt::title("DIY filter");
    plt::show();

    //時間軸方向でkaiser窓掛ける
    Eigen::VectorXd vector_time_vec = Eigen::Map<Eigen::VectorXd>(&time_vec[0],time_vec.size());
    Eigen::VectorXd kaiser_window = vsp::getKaiserWindow(time_vec.size(),8).array();
//    Eigen::VectorXd buff2(kaiser_window.rows());
//    buff2.block(0,0,kaiser_window.rows()/2,1) = kaiser_window.block(kaiser_window.rows()/2,0,kaiser_window.rows()/2,1);
//    buff2.block(kaiser_window.rows()/2,0,kaiser_window.rows()-kaiser_window.rows()/2,1) = kaiser_window.block(0,0,kaiser_window.rows()-kaiser_window.rows()/2,1);

    vector_time_vec = vector_time_vec.array() * kaiser_window.array();
    Eigen::Map<Eigen::VectorXd>(&time_vec[0],vector_time_vec.rows(),1) = vector_time_vec;
    fft.fwd(freq_vec,time_vec);
    for(int i=0,e=time_vec.size();i<e;++i){
        vec_real[i] = freq_vec[i].real();
        vec_imag[i] = freq_vec[i].imag();
    }

    plot_eigen(time,time_vec,".-r");
    plt::title("DIY filter coeff with kaiser");
    plt::show();

    plot_eigen(time,vec_real,".-g");
    plot_eigen(time,vec_imag,".-b");
    plt::title("DIY filter with kaiser");
    plt::show();



    return 0;
}

