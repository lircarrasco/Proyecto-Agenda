#ifndef CONTACTO_H
#define CONTACTO_H


class Contacto
{
    public:
        Contacto();
        virtual ~Contacto();
        Contacto(const Contacto& other);

        string Getphone_number() { return phone_number; }
        void Setphone_number(string val) { phone_number = val; }
        string Getnombe() { return nombe; }
        void Setnombe(string val) { nombe = val; }
        string Getcorreo() { return correo; }
        void Setcorreo(string val) { correo = val; }

    protected:
        string phone_number;
        string nombe;
        string correo;

    private:
};

#endif // CONTACTO_H
