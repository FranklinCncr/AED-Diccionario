#pragma once
#include "Lista.h"
#include <fstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace System;
namespace Diccionario {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	void MarshalString(String ^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	void MarshalString(String ^ s, wstring& os) {
		using namespace Runtime::InteropServices;
		const wchar_t* chars =
			(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	Lista<string> List;	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:		
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  palabra;



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buscar;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  direccionArchivo;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  radio;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  resultados;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  cargar;

	private: System::Windows::Forms::TextBox^  tiempocarga;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  ram;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tiempoBusqueda;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button1;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->palabra = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buscar = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->direccionArchivo = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radio = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->resultados = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cargar = (gcnew System::Windows::Forms::Button());
			this->tiempocarga = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->ram = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tiempoBusqueda = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::Window;
			this->label1->Location = System::Drawing::Point(75, 123);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Archivo";
			// 
			// palabra
			// 
			this->palabra->Location = System::Drawing::Point(596, 118);
			this->palabra->Name = L"palabra";
			this->palabra->Size = System::Drawing::Size(237, 20);
			this->palabra->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::Window;
			this->label2->Location = System::Drawing::Point(504, 123);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Buscar Palabra";
			// 
			// buscar
			// 
			this->buscar->Location = System::Drawing::Point(846, 116);
			this->buscar->Name = L"buscar";
			this->buscar->Size = System::Drawing::Size(75, 23);
			this->buscar->TabIndex = 4;
			this->buscar->Text = L"Buscar";
			this->buscar->UseVisualStyleBackColor = true;
			this->buscar->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Window;
			this->label3->Location = System::Drawing::Point(504, 205);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 15);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Salida";
			// 
			// direccionArchivo
			// 
			this->direccionArchivo->Location = System::Drawing::Point(137, 119);
			this->direccionArchivo->Name = L"direccionArchivo";
			this->direccionArchivo->Size = System::Drawing::Size(267, 20);
			this->direccionArchivo->TabIndex = 6;
			this->direccionArchivo->Text = L"Recursos/diccionario.txt";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Window;
			this->label4->Location = System::Drawing::Point(504, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 15);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Radio";
			// 
			// radio
			// 
			this->radio->Location = System::Drawing::Point(596, 160);
			this->radio->Name = L"radio";
			this->radio->Size = System::Drawing::Size(96, 20);
			this->radio->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::Window;
			this->label5->Location = System::Drawing::Point(723, 162);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 15);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Resultados";
			// 
			// resultados
			// 
			this->resultados->Location = System::Drawing::Point(806, 160);
			this->resultados->Name = L"resultados";
			this->resultados->ReadOnly = true;
			this->resultados->Size = System::Drawing::Size(115, 20);
			this->resultados->TabIndex = 11;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Arboles Red Black", L"Listas Enlazadas", L"Arboles Binarios",
					L"Pilas", L"Colas", L"Heaps"
			});
			this->comboBox1->Location = System::Drawing::Point(188, 166);
			this->comboBox1->Name = L"cargar";
			this->comboBox1->Size = System::Drawing::Size(216, 21);
			this->comboBox1->TabIndex = 12;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cargar_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::Window;
			this->label6->Location = System::Drawing::Point(75, 171);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(113, 15);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Estructura de Datos";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::Window;
			this->label7->Location = System::Drawing::Point(75, 420);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(97, 15);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Tiempo de Carga";
			// 
			// cargar
			// 
			this->cargar->Location = System::Drawing::Point(78, 363);
			this->cargar->Name = L"cargar";
			this->cargar->Size = System::Drawing::Size(326, 23);
			this->cargar->TabIndex = 15;
			this->cargar->Text = L"Cargar";
			this->cargar->UseVisualStyleBackColor = true;
			this->cargar->Click += gcnew System::EventHandler(this, &MyForm::cargar_Click);
			// 
			// tiempocarga
			// 
			this->tiempocarga->Location = System::Drawing::Point(188, 418);
			this->tiempocarga->Name = L"tiempocarga";
			this->tiempocarga->ReadOnly = true;
			this->tiempocarga->Size = System::Drawing::Size(216, 20);
			this->tiempocarga->TabIndex = 16;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::Window;
			this->label8->Location = System::Drawing::Point(75, 462);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(147, 15);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Cantidad de Memoria Ram";
			// 
			// ram
			// 
			this->ram->Location = System::Drawing::Point(241, 460);
			this->ram->Name = L"ram";
			this->ram->ReadOnly = true;
			this->ram->Size = System::Drawing::Size(163, 20);
			this->ram->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::Window;
			this->label9->Location = System::Drawing::Point(75, 503);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(120, 15);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Tiempo de Busqueda";
			// 
			// tiempoBusqueda
			// 
			this->tiempoBusqueda->Location = System::Drawing::Point(214, 501);
			this->tiempoBusqueda->Name = L"tiempoBusqueda";
			this->tiempoBusqueda->ReadOnly = true;
			this->tiempoBusqueda->Size = System::Drawing::Size(190, 20);
			this->tiempoBusqueda->TabIndex = 20;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(137, 206);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(208, 145);
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(596, 204);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(325, 329);
			this->listBox1->TabIndex = 22;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(507, 240);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 24);
			this->button1->TabIndex = 23;
			this->button1->Text = L"Mostrar ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::mostrar_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1007, 600);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->tiempoBusqueda);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->ram);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tiempocarga);
			this->Controls->Add(this->cargar);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->resultados);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->radio);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->direccionArchivo);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->buscar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->palabra);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Diccionario";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		listBox1->Items->Clear();
		string busqueda,resultado;
		MarshalString(palabra->Text, busqueda);
		resultado=List.find(busqueda);
		listBox1->Items->Add(gcnew String(resultado.c_str()));
		resultados->Text = L"1";
		
	}
   
	private: System::Void cargar_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void cargar_Click(System::Object^  sender, System::EventArgs^  e) {
		string direccion,palabra,trd;
		char cadena[128];
		MarshalString(direccionArchivo->Text, direccion);
		std::ifstream archivo(direccion);
		while(archivo){
			archivo >> palabra;			
			archivo >> trd;
			archivo.getline(cadena,128);
			trd = trd+cadena;
			List.pushBack(palabra, trd);
			
		}
		archivo.close();
		listBox1->Items->Clear();
		listBox1->Items->Add("Listo");
	}
	private: System::Void mostrar_Click(System::Object^  sender, System::EventArgs^  e) {
				 //MUESTRA DESDE LA ESTRUCTURA DE DATOS
				 listBox1->Items->Clear();
				 int cont = 0;
				 Nodo<string> *aux = List.m_pHead;
				 while (aux){					 
					 string cadena = aux->m_palabra + "     Traduccion = " + aux->m_traduccion;
					 listBox1->Items->Add(gcnew String(cadena.c_str()));
					 aux=aux->m_psig;
					 cont++;
				 }				 
				resultados->Text = System::Convert::ToString(cont);
				 //MUESTRA AL LEER
				 /*listBox1->Items->Clear();
				 string direccion, palabra, trd;
				 char cadena[128];
				 MarshalString(direccionArchivo->Text, direccion);
				 ifstream archivo(direccion);
				 while(archivo){
					 archivo >> palabra;
					 archivo >> trd;
					 archivo.getline(cadena, 128);
					 trd = palabra+"      Traduccion = "+trd + cadena;
					 listBox1->Items->Add(gcnew String(trd.c_str()));
				 }
				 archivo.close();*/
	}
};
}
