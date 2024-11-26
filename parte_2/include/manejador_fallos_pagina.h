#pragma once


class ManejadorFallosPagina {
    public:
        virtual void push(int valor) = 0;
        virtual int getHits() = 0;
        virtual int getMisses() = 0;
};