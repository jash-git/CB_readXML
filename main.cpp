#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"
using namespace std;
void printNode(TiXmlNode* node);
int main()
{
    cout << "Hello world!" << endl;
	TiXmlDocument doc("test_jash.xml");
	doc.LoadFile();
	TiXmlNode *root = doc.RootElement();
	printNode(root);
    return 0;
}
void printNode(TiXmlNode* node) //�j��C�L�Ҧ����`�I
{
	if(node == NULL) return;
		cout<<"["<<node->Value()<<"]"<<endl; //��ܸ`�I���W��
	TiXmlElement* element = node->ToElement();

	if(element && element->GetText()) //��ܸ`�I�����e
           	cout<<"      -->"<< element->GetText()<<endl;

	if(element && element->FirstAttribute()) //��ܸ`�I�ݩ�
	{
		TiXmlAttribute *IDAttribute = element->FirstAttribute();
		while ( IDAttribute )
		{
			cout<<"      -->"<<"Attribute name="<<IDAttribute->Name()<<"\t";
			cout<<"       ::"<< IDAttribute->Value() << endl;
			IDAttribute=IDAttribute->Next();
		}
	}

	TiXmlElement* child = node->FirstChildElement();
	while(child!=NULL)
	{
		printNode(child); //���j�ե���ܸ`�I
		child = child->NextSiblingElement();
	}
}
