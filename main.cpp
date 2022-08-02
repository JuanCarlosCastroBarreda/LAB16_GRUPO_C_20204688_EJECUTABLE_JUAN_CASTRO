#include <iostream>
#include <string>
#include <vector>

//Windows

class WindowsFactory {
    public:
    virtual ~WindowsFactory() {};
    virtual std::string Draw() const = 0;
};

class WindowsButton : public WindowsFactory {
    public:
    std::string Draw() const override {
        return "Dibujando Button Windows";
    }
};

class WindowsCheckBox : public WindowsFactory {
    std::string Draw() const override {
        return "Dibujando CheckBox Windows";
    }
};

//Mac

class MacFactory {
    public:
    virtual ~MacFactory() {};
    virtual std::string Draw() const = 0;
    virtual std::string draw(const WindowsFactory& colaborador) const = 0;
};

class MacButton : public MacFactory {
    public:
        std::string Draw() const override {
            return "Dibujando Button Mac";
        }
        std::string draw(const WindowsFactory& colaborador) const 

    override {
        const std::string result = colaborador.Draw();
        return "Dibujando Button Mac con ayuda de " + result;
        }
};

class MacCheckBox : public MacFactory {
    public:
        std::string Draw() const override {
            return "Dibujando CheckBox Mac";
        }
        std::string draw(const WindowsFactory& colaborador) const 

    override {
        const std::string result = colaborador.Draw();
        return "Dibujando CheckBox Mac con ayuda de " + result;
        }
};

//Linux

class LinuxFactory {
    public:
    virtual ~LinuxFactory() {};
    virtual std::string Draw() const = 0;
    virtual std::string draw(const WindowsFactory& colaborador) const = 0;
};

class LinuxButton : public LinuxFactory {
    public:
        std::string Draw() const override {
            return "Dibujando Button Linux";
        }
        std::string draw(const WindowsFactory& colaborador) const 

    override {
        const std::string result = colaborador.Draw();
        return "Dibujando Button Linux con ayuda de " + result;
        }
};

class LinuxCheckBox : public LinuxFactory {
    public:
        std::string Draw() const override {
            return "Dibujando CheckBox Linux";
        }
        std::string draw(const WindowsFactory& colaborador) const 

    override {
        const std::string result = colaborador.Draw();
        return "Dibujando CheckBox Linux con ayuda de " + result;
        }
};

class InterfazFactory {
    public:
    virtual WindowsFactory* CrearInterfazWindows() const = 0;
    virtual MacFactory* CrearInterfazMac() const = 0;
    virtual LinuxFactory* CrearInterfazLinux() const = 0;
};

class Button : public InterfazFactory {
    public:
    WindowsFactory* CrearInterfazWindows() const override {
        return new WindowsButton();
    }

    MacFactory* CrearInterfazMac() const override {
        return new MacButton();
    }

    LinuxFactory* CrearInterfazLinux() const override {
        return new LinuxButton();
    }
};

class CheckBox : public InterfazFactory {
    public:
    WindowsFactory* CrearInterfazWindows() const override {
        return new WindowsCheckBox();
    }

    MacFactory* CrearInterfazMac() const override {
        return new MacCheckBox();
    }

    LinuxFactory* CrearInterfazLinux() const override {
        return new LinuxCheckBox();
    }
};

void Aplication(const InterfazFactory& f, int opcion){
    if (opcion == 1){
        const WindowsFactory* producto = f.CrearInterfazWindows();
        std::cout <<"\n"<< producto->Draw() << "\n";
        delete producto;
    }else if(opcion == 2){
        const MacFactory* producto = f.CrearInterfazMac();
        std::cout <<"\n"<< producto->Draw() << "\n";
        delete producto;
    }else if(opcion == 3){
        const LinuxFactory* producto = f.CrearInterfazLinux();
        std::cout <<"\n"<< producto->Draw() << "\n";
        delete producto;
    }
}

int main() {
    std::cout << "Cliente: Windows ";
    Button* f1 = new Button();
    Aplication(*f1, 1); // 1 - Windows
    delete f1;

    std::cout << std::endl;
    std::cout << "Cliente: Mac ";
    Button* f2 = new Button();
    Aplication(*f2, 2); // 2 - Mac
    delete f2;
    
    std::cout << std::endl;
    std::cout << "Cliente: Linux ";
    Button* f3 = new Button();
    Aplication(*f3, 3); // 3 - Linux
    delete f3;
    return 0;
}