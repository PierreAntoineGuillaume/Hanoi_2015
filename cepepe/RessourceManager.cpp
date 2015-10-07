//
// Created by g20901528 on 07/10/15.
//

#include "RessourceManager.h"

using namespace std;
using namespace nsHanoi;


nsHanoi::RessourceManager ()
{
}

nsHanoi::RessourceManager & nsHanoi::RessourceManager::getInstance () noexcept
{
    static nsHanoi::RessourceManager i;
    return i;
}

void nsHanoi::RessourceManager::Initialize_All_Cubes () noexcept
{

    const float biggest_disk = 4;
    const float offset = 1;
    const int square = 1;

    const int number_of_disks = 5;

    const float disk_height = 1;

    const float half = square/2;

    const float base_height = 1;

    const int number_of_pikes = 3;

    const float delta_decrease = 0.5f;

    //support
    Point A(0,0,0);
    Point B(-(2*offset + biggest_disk),0,0);
    Point D(0,(2*offset + biggest_disk) * number_of_pikes,0);
    Point E(0,0,base_height);


    vect.reserve(9);
    vect.push_back (Cube(new Cuboid(A,B,D,E)));

    //tiges
    for (unsigned i (0);i< number_of_pikes;++i)
    {
        A = Point((2*offset + biggest_disk) / 2 + half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 - half, 0);
        B = Point((2*offset + biggest_disk) / 2 + half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 + half, 0);
        D = Point((2*offset + biggest_disk) / 2 - half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 - half, 0);
        E = Point((2*offset + biggest_disk) / 2 + half, (i * (2*offset + biggest_disk)) * (2*offset + biggest_disk) / 2 - half,
                  base_height + (number_of_disks * disk_height));

        vect.push_back(Cube(new Cuboid(A, B, D, E)));
    }

    //disks
    for (unsigned i (0);i<number_of_disks;++i)
    {
        float a = offset + i * delta_decrease;
        Point A_(a,a,base_height + i * disk_height);
        Point B_(a,a + (biggest_disk - (delta_decrease * i * 2)),
                 base_height + i * disk_height);
        Point D_(a + (biggest_disk - (delta_decrease * i * 2)),a,
                 base_height + i * disk_height);
        Point E_(a,a,base_height + (i + 1) * disk_height);

        vect.push_back(Cube(new Cuboid(A_, B_, D_, E_)));

    }
}

void nsHanoi::RessourceManager::RenderAll() const noexcept
{
    /** /
    for (Cube i : vect)
        *i.Afficher();
    /**/
}