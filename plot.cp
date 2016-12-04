void plot()
{
    gStyle->SetOptStat(000);
    Float_t city, year, univ, fac;
    
    
    FILE *f1 = fopen("aus1.txt","r");
    FILE *f2 = fopen("aus2.txt","r");
    FILE *f3 = fopen("aus3.txt","r");
    
    
    Float_t Uni1[20000], Uni2[20000], Uni3[20000];
    Float_t City1[20000], City2[20000], City3[20000];
    Float_t Year1[20000], Year2[20000], Year3[20000];
    
    
    Int_t i;
    i=0;
    
    while (fscanf(f1,"%f,%f,%f,%f", &City1[i],&Year1[i],&Uni1[i],&fac) != EOF)
    {
        i++;
    }
    Int_t N1=i;
    
    while (fscanf(f2,"%f,%f,%f,%f", &City2[i],&Year2[i],&Uni2[i],&fac) != EOF)
    {
        i++;
    }
    Int_t N2=i;
    
    while (fscanf(f3,"%f,%f,%f,%f", &City3[i],&Year3[i],&Uni3[i],&fac) != EOF)
    {
        i++;
    }
    Int_t N3=i;

    int nBinsUni = 100;
    int startUni = 1;
    TH1F* Univ1 = new TH1F("Univ1","Univ1",nBinsUni,startUni*nBinsUni+1,(startUni+1)*nBinsUni+1);
    TH1F* Univ2 = new TH1F("Univ2","Univ2",nBinsUni,startUni*nBinsUni+1,(startUni+1)*nBinsUni+1);
    TH1F* Univ3 = new TH1F("Univ3","Univ3",nBinsUni,startUni*nBinsUni+1,(startUni+1)*nBinsUni+1);

    
    
    int startYea = 1940;
    int finishYea = 2020;
    int nBinsYea = finishYea-startYea;
    TH1F* Yea1 = new TH1F("Yea1","Yea1",nBinsYea,startYea,finishYea);
    TH1F* Yea2 = new TH1F("Yea2","Yea2",nBinsYea,startYea,finishYea);
    TH1F* Yea3 = new TH1F("Yea3","Yea3",nBinsYea,startYea,finishYea);
    
    for(int i=0;i<N1;i++)
    {
        Univ1->Fill(Uni1[i]);
        Yea1->Fill(Year1[i]);
    }
    
    for(int i=0;i<N2;i++)
    {
        Univ2->Fill(Uni2[i]);
        Yea2->Fill(Year2[i]);
    }
    
    for(int i=0;i<N3;i++)
    {
        Univ3->Fill(Uni3[i]);
        Yea3->Fill(Year3[i]);
    }
    

    
    float NN1 = Univ1->Integral();
    float NN2 = Univ2->Integral();
    float NN3 = Univ3->Integral();
    
    for(int i=0;i<nBinsUni;i++)
    {
        
        float un1 = Univ1->GetBinContent(i+1);
        float un2 = Univ2->GetBinContent(i+1);
        float un3 = Univ3->GetBinContent(i+1);
        
        
        float average = (un1+un2+un3)/3.;
        if(average==0)average=1;
        
//        Univ1->SetBinContent(i+1,un1/average);
//        Univ1->SetBinError(i+1,TMath::Sqrt(un1)/average);
//        
//        Univ2->SetBinContent(i+1,un2/average);
//        Univ2->SetBinError(i+1,TMath::Sqrt(un2)/average);
//        
//        Univ3->SetBinContent(i+1,un3/average);
//        Univ3->SetBinError(i+1,TMath::Sqrt(un3)/average);
        
        Univ1->SetBinContent(i+1,un1/float(NN1));
        Univ1->SetBinError(i+1,TMath::Sqrt(un1)/float(NN1));
        
        Univ2->SetBinContent(i+1,un2/float(NN2));
        Univ2->SetBinError(i+1,TMath::Sqrt(un2)/float(NN2));
        
        Univ3->SetBinContent(i+1,un3/float(NN3));
        Univ3->SetBinError(i+1,TMath::Sqrt(un3)/float(NN3));
        
    }

    
    
    float Nn1 = Yea1->Integral();
    float Nn2 = Yea2->Integral();
    float Nn3 = Yea3->Integral();
    for(int i=0;i<nBinsYea;i++)
    {
        
        float ye1 = Yea1->GetBinContent(i+1);
        float ye2 = Yea2->GetBinContent(i+1);
        float ye3 = Yea3->GetBinContent(i+1);
        
        float averageye = (ye1+ye2+ye3)/3.;
        if(averageye==0)averageye=1;
        
        
        Yea1->SetBinContent(i+1,ye1/float(Nn1));
        Yea1->SetBinError(i+1,TMath::Sqrt(ye1)/float(Nn1));
        
        Yea2->SetBinContent(i+1,ye2/float(Nn2));
        Yea2->SetBinError(i+1,TMath::Sqrt(ye2)/float(Nn2));
        
        Yea3->SetBinContent(i+1,ye3/float(Nn3));
        Yea3->SetBinError(i+1,TMath::Sqrt(ye3)/float(Nn3));
        
    }

    

    
    TCanvas* c1 = new TCanvas("c1","c1",800,600);
    c1->SetLogy();
    
    Univ1->Draw("E");
    Univ2->SetLineColor(kGreen);
    Univ2->Draw("barsame");
    Univ3->SetLineColor(kRed);
    Univ3->Draw("Esame");
    
//    TCanvas* c2 = new TCanvas("c2","c2",800,600);
//    c2->SetLogy();
//    Yea1->Draw("E");
//    Yea2->SetLineColor(kGreen);
//    Yea2->Draw("barsame");
//    Yea3->SetLineColor(kRed);
//    Yea3->Draw("Esame");
}