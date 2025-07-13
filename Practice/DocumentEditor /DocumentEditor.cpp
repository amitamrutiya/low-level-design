#include <iostream>
#include <vector>
#include <string>
#include <fstream>
// using namespace std;

// class DocumentEditor
// {
// private:
//     vector<string> documentElement;
//     string renderedDocument;

// public:
//     void addText(string text)
//     {
//         documentElement.push_back(text);
//     }

//     void addImage(string text)
//     {
//         documentElement.push_back(text);
//     }

//     string renderDocument()
//     {
//         if (renderedDocument.empty())
//         {
//             string result;
//             for (string element : documentElement)
//             {
//                 if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" || element.substr(element.size() - 4) == ".png"))
//                 {
//                     result += "Image" + element + "\n";
//                 }
//                 else
//                 {
//                     result += "Text: " + element + "\n";
//                 }
//             }
//             renderedDocument = result;
//         }
//         return renderedDocument;
//     }

//     void saveFile()
//     {
//         ofstream file("document.txt");
//         if (file.is_open())
//         {
//             file << renderedDocument;
//             file.close();
//             cout << "File saved successfully." << endl;
//         }
//         else
//         {
//             cout << "Error opening file for saving." << endl;
//         }
//     }
// };

// int main()
// {
//     DocumentEditor editor;
//     editor.addText("Hello, World!");
//     editor.addImage("image1.jpg");
//     editor.addText("This is a sample document.");
//     editor.addImage("image2.png");

//     cout << "Rendered Document:\n"
//          << editor.renderDocument() << endl;

//     editor.saveFile();

//     return 0;
// }

using namespace std;

class DocumentElement
{
public:
    virtual ~DocumentElement() = default;
    virtual string render() const = 0;
};

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }
    string render() const override
    {
        return "Text: " + text + "\n";
    }
};

class ImageElement : public DocumentElement
{
private:
    string image;

public:
    ImageElement(string image)
    {
        this->image = image;
    }
    string render() const override
    {

        return "Image" + image + "\n";
    }
};

class NewLineElement : public DocumentElement
{

public:
    string render() const override
    {
        return "\n";
    }
};

class TabSpaceElement : public DocumentElement
{
public:
    string render() const override
    {
        return "\t";
    }
};

class Document
{
private:
    vector<DocumentElement *> elements;

public:
    void addElements(DocumentElement *element)
    {
        elements.push_back(element);
    }

    string render()
    {
        string result;
        for (auto element : elements)
        {
            result += element->render();
        }
        return result;
    }
};

class Persistences
{
public:
    virtual void save(string data) = 0;
};

class SaveToFile : public Persistences
{
public:
    void save(string renderedDocument) override
    {
        ofstream file("document.txt");
        if (file.is_open())
        {
            file << renderedDocument;
            file.close();
            cout << "File saved successfully." << endl;
        }
        else
        {
            cout << "Error opening file for saving." << endl;
        }
    }
};

class SaveToDB : public Persistences
{
    void save(string data) override
    {
        cout << "Save to database implemented" << endl;
    }
};

class DocumentEditor
{
private:
    Document *doc;
    Persistences *storage;
    string renderedDocument;

public:
    DocumentEditor(Document *doc, Persistences *storage)
    {
        this->doc = doc;
        this->storage = storage;
    }

    void addText(string text)
    {
        doc->addElements(new TextElement(text));
    }

    void addImage(string path)
    {
        doc->addElements(new ImageElement(path));
    }

    void addNewLine()
    {
        doc->addElements(new NewLineElement());
    }

    void addTabSpace()
    {
        doc->addElements(new TabSpaceElement());
    }

    string renderDoc()
    {
        if (renderedDocument.empty())
        {
            renderedDocument = doc->render();
        }
        return renderedDocument;
    }

    void save()
    {
        storage->save(renderDoc());
    }
};

int main()
{
    Document *document = new Document();
    Persistences *persistence = new SaveToFile();

    DocumentEditor *editor = new DocumentEditor(document, persistence);

    // Simulate a client using the editor with common text formatting features.
    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderDoc() << endl;

    editor->save();

    return 0;
}