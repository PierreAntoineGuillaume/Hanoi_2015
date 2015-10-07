//
// Created by g20901528 on 07/10/15.
//



#pragma once

#include <memory>
#include <vector>

#include "Cuboid.h"


typedef std::unique_ptr<nsHanoi::Cuboid> Cube;


namespace nsHanoi
{
    class RessourceManager
    {
    private:
        RessourceManager ();
        std::vector<Cube> vect;
        RessourceManager operator = (const RessourceManager &) = delete;
        RessourceManager (const RessourceManager &) = delete;
        void Initialize_All_Cubes () noexcept;
    public:
        RessourceManager & getInstance () noexcept;
        void add(const Cuboid & elem) noexcept;
        void RenderAll() const noexcept;

    };
}