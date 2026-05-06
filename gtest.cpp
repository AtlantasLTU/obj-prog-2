#include <gtest/gtest.h>
#include "./vector/studentas.h"
#include <sstream>
#include <memory>

// 1. Kopijavimo konstruktorius
TEST(RuleOfFive, CopyConstructor)
{
    Studentas A("A", "AAA", {1, 2}, 10);
    Studentas B(A);
    
    EXPECT_EQ(B.getVardas(), "A");
    EXPECT_EQ(B.getPavarde(), "AAA");
    EXPECT_EQ(B.getNd().size(), 2);
    EXPECT_EQ(B.getRez(), 10);
}

// 2. Kopijavimo priskyrimas
TEST(RuleOfFive, CopyAssignment)
{
    Studentas A("A", "AAA", {1, 2}, 10);
    Studentas B;
    B = A;

    EXPECT_EQ(B.getVardas(), "A");
    EXPECT_EQ(B.getPavarde(), "AAA");
    EXPECT_EQ(B.getNd().size(), 2);
    EXPECT_EQ(B.getRez(), 10);
}

// 3. Perkėlimo konstruktorius
TEST(RuleOfFive, MoveConstructor)
{
    Studentas A("A", "AAA", {1, 2}, 10);
    Studentas B(std::move(A));
    
    EXPECT_EQ(B.getVardas(), "A");
    EXPECT_EQ(B.getPavarde(), "AAA");
    EXPECT_EQ(B.getNd().size(), 2);
    EXPECT_EQ(B.getRez(), 10);
    EXPECT_TRUE(A.getVardas().empty());
    EXPECT_TRUE(A.getPavarde().empty());
    EXPECT_TRUE(A.getNd().empty());
    EXPECT_EQ(A.getRez(), 0);
}

// 4. Perkėlimo priskyrimas
TEST(RuleOfFive, MoveAssignment)
{
    Studentas A("A", "AAA", {1, 2}, 10);
    Studentas B;
    B = std::move(A);
    
    EXPECT_EQ(B.getVardas(), "A");
    EXPECT_EQ(B.getPavarde(), "AAA");
    EXPECT_EQ(B.getNd().size(), 2);
    EXPECT_EQ(B.getRez(), 10);
    EXPECT_TRUE(A.getVardas().empty());
    EXPECT_TRUE(A.getPavarde().empty());
    EXPECT_TRUE(A.getNd().empty());
    EXPECT_EQ(A.getRez(), 0);
}

// 5. Destruktorius
TEST(RuleOfFive, Destructor)
{
    std::weak_ptr<Studentas> weak;
    {
        std::shared_ptr<Studentas> A = std::make_shared<Studentas>("A", "AAA", std::vector<int>{1,2}, 10);
        weak = A;
    }
    EXPECT_TRUE(weak.expired());
}

// 6. Papildomas: galutinis() su mediana
TEST(Functional, MedianCalculation)
{
    Studentas A("A", "AAA", {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
    double result = A.galutinis(true, 10);
    EXPECT_DOUBLE_EQ(result, 8.2);
}