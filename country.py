from ROOT import *

gStyle.SetOptStat(000)

tree0 = TTree("0","0")
tree1 = TTree("1","1")
tree2 = TTree("2","2")



id0 =0; P_country0 =0; P_city0=0; grad_year0=0; uni0=0; faculty0=0; uni_country0=0; uni_city0=0; foreign0=0
id1 =0; P_country1 =0; P_city1=0; grad_year1=0; uni1=0; faculty1=0; uni_country1=0; uni_city1=0; foreign1=0
id2 =0; P_country2 =0; P_city2=0; grad_year2=0; uni2=0; faculty2=0; uni_country2=0; uni_city2=0; foreign2=0


tree0.Branch("ID",id0,"ID/I")
tree0.Branch("P_country", P_country0,"P_country/I")
tree0.Branch("P_city", P_city0,"P_city/I")
tree0.Branch("grad_year", grad_year0,"grad_year/I")
tree0.Branch("uni", uni0,"uni/I")
tree0.Branch("faculty", faculty0,"faculty/I")
tree0.Branch("uni_country", uni_country0,"uni_country/I")
tree0.Branch("uni_city", uni_city0,"uni_city/I")
tree0.Branch("foreign", foreign0,"foreign/I")

tree1.Branch("ID", id1,"ID/I")
tree1.Branch("P_country", P_country1,"P_country/I")
tree1.Branch("P_city", P_city1,"P_city/I")
tree1.Branch("grad_year", grad_year1,"grad_year/I")
tree1.Branch("uni", uni1,"uni/I")
tree1.Branch("faculty", faculty1,"faculty/I")
tree1.Branch("uni_country", uni_country1,"uni_country/I")
tree1.Branch("uni_city", uni_city1,"uni_city/I")
tree1.Branch("foreign", foreign1,"foreign/I")


tree2.Branch("ID", id2,"ID/I")
tree2.Branch("P_country", P_country2,"P_country/I")
tree2.Branch("P_city", P_city2,"P_city/I")
tree2.Branch("grad_year", grad_year2,"grad_year/I")
tree2.Branch("uni", uni2,"uni/I")
tree2.Branch("faculty", faculty2,"faculty/I")
tree2.Branch("uni_country", uni_country2,"uni_country/I")
tree2.Branch("uni_city", uni_city2,"uni_city/I")
tree2.Branch("foreign", foreign2,"foreign/I")


hist0 = TH2F("hist0","hist0",24,1992,2016,100,0,1.5)
hist1 = TH2F("hist1","hist1",24,1992,2016,100,0,1.5)
hist2 = TH2F("hist2","hist2",24,1992,2016,100,0,1.5)



year0 = TH1F("year0","year0",24,1992,2016)
year1 = TH1F("year1","year1",24,1992,2016)
year2 = TH1F("year2","year2",24,1992,2016)

with open("Data/univ-vs-country-0.txt") as f0:
    for line in f0:
       id0, P_country0, P_city0, grad_year0, uni0, faculty0, uni_country0, uni_city0 = [int(x) for x in line.split(",")]
       foreign0 = int(P_country0!=2)
       hist0.Fill(grad_year0,foreign0)
       year0.Fill(grad_year0)
       tree0.Fill()

with open("Data/univ-vs-country-1.txt") as f1:
    for line in f1:
       id1, P_country1, P_city1, grad_year1, uni1, faculty1, uni_country1, uni_city1 = [int(x) for x in line.split(",")]
       foreign1=int(P_country1!=2)
       hist1.Fill(grad_year1,foreign1)
       year1.Fill(grad_year1)
       tree1.Fill()

with open("Data/univ-vs-country-2.txt") as f2:
    for line in f2:
       id2, P_country2, P_city2, grad_year2, uni2, faculty2, uni_country2, uni_city2 = [int(x) for x in line.split(",")]
       foreign2=int(P_country2!=2)
       hist2.Fill(grad_year2,foreign2)
       year2.Fill(grad_year2)
       tree2.Fill()


tree0.SaveAs("Data/tree0.root")
tree1.SaveAs("Data/tree1.root")
tree2.SaveAs("Data/tree2.root")

c1 = TCanvas("c1","c1",800,600)
profX0 = hist0.ProfileX()
profX1 = hist1.ProfileX()
profX1.SetLineColor(kRed)
profX2 = hist2.ProfileX()
profX2.SetLineColor(kGreen)

profX0.Draw()
profX1.Draw("same")
profX2.Draw("same")


c2 = TCanvas("c2","c2",800,600)
year1.SetLineColor(kRed)
year2.SetLineColor(kGreen)
year1.Draw("E")
year0.Draw("Esame")
year2.Draw("Esame")

c2.SaveAs("c2.pdf")
