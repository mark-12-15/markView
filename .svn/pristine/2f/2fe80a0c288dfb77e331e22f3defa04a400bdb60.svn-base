#include "BCXMLManager.h"
#include <QtXml>
#include <QFile>
#include <QDebug>
#include <QDomNamedNodeMap>
BCXMLManager::BCXMLManager(QString fileName)
{
    _fileName = fileName;
    _sort = 1;
}

bool BCXMLManager::CreateXMLFile(QString fileName)
{
    if(fileName.size()>4)
    {
        if(fileName.right(4) != ".xml")
        {
            fileName.append(".xml");
        }

    }
    else
    {
        fileName.append(".xml");
    }
    QDomProcessingInstruction instruction;
    instruction = _doc.createProcessingInstruction("xml","version = \"1.0\" encoding = \"UTF-8\"");
    _doc.appendChild(instruction);
    QDomElement root = _doc.createElement("BR");
    _doc.appendChild(root);
    _fileName = fileName;
   return this->Save();

}

bool BCXMLManager::IsExistXmlFile(QString fileName)
{
    if(fileName.size()>4){
        if(fileName.right(4) != ".xml"){
            fileName.append(".xml");
        }

    }else{
        fileName.append(".xml");
    }
    _fileName = fileName;
    QFile file(_fileName);
    if(!file.open(QIODevice::ReadOnly)){
       return false;
    }
    file.close();

    return true;
}

bool BCXMLManager::ContainTheNode(QString nodeName)
{
     QDomElement el = this->FindElementByNodeName(nodeName);
     if(el.tagName() == nodeName) return true;

         return false;
}

bool BCXMLManager::MoveNodeTo(QString nodeName, int to)
{
    QFile file(_fileName);
    if(!file.open(QIODevice::ReadOnly)) return false;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        return false;
    }
    file.close();
     QDomElement root = doc.documentElement();
     for(int i = 0; i < root.childNodes().count(); i++)
     {
         if(root.childNodes().at(i).isElement())
         {
             QDomElement node = root.childNodes().at(i).toElement();

             if(node.tagName() == nodeName)
             {
                 if(to < 0 || to >= root.childNodes().count()) return false;
                 QDomNode temp;


                 temp = root.replaceChild(root.childNodes().at(i),root.childNodes().at(to));
                 if(to > i)
                 {
                     root.insertBefore(temp,root.childNodes().at(i + to - 1));

                 }
                 else
                 {
                     root.insertAfter(temp,root.childNodes().at(to));
                 }

                 if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return false;
                 QTextStream out(&file);
                 root.save(out,4);
                 file.close();
                 return true;
             }
         }
     }
     return false;
}

bool BCXMLManager::CreateNode(QString nodeName)
{
    QFile file(_fileName);
    if(!file.open(QIODevice::ReadOnly)) return false;
    if(!_doc.setContent(&file))
    {
        file.close();
        return false;
    }
    file.close();
     QDomElement root = _doc.documentElement();
     QDomElement first = _doc.createElement(nodeName);
     root.appendChild(first);
    return this->Save();
}

bool BCXMLManager::AddAttribute(QString nodeName, QMap<QString, QString> map)
{
    QDomElement el = this->FindElementByNodeName(nodeName);
    for(int i = 0;i<map.keys().size();i++)
    {
        el.setAttribute(map.keys().at(i),map.values().at(i));
    }

   return this->Save();
}

bool BCXMLManager::UpdateAttribute(QString nodeName, QString key, QString value)
{
    QDomElement el = this->FindElementByNodeName(nodeName);
    if(el.attributes().contains(key))
    {
         el.removeAttribute(key);
         el.setAttribute(key,value);
         return this->Save();
    }
    return false;
}

bool BCXMLManager::UpdateAttributes(QString nodeName, QMap<QString, QString> map)
{
     QDomElement el = this->FindElementByNodeName(nodeName);
     for(int i = 0;i<map.keys().size();i++)
     {
             if(el.attributes().contains(map.keys().at(i)))
             {
                 el.removeAttribute(map.keys().at(i));
                 el.setAttribute(map.keys().at(i),map.value(map.keys().at(i)));
             }
     }
     return this->Save();
}

bool BCXMLManager::DeleateNode(QString nodeName)
{
    this->CorrectedNode();
    for(int i = 0; i <_doc.documentElement().childNodes().count();i++)
    {
        if(_doc.documentElement().childNodes().at(i).nodeName() == nodeName)
        {
            _doc.documentElement().removeChild(_doc.documentElement().childNodes().at(i));
            return this->Save();
        }
    }
    return false;
}

bool BCXMLManager::DeleateNodeAt(int index)
{
    this->CorrectedNode();
    if(_doc.documentElement().childNodes().count() > 0)
    {
        _doc.documentElement().removeChild(_doc.documentElement().childNodes().at(index));
        return this->Save();
    }
    return false;
}

QString BCXMLManager::GetLastNode()
{
    return GetNode();
}

QString BCXMLManager::GetNodeAt(int index)
{
    return GetNode(index);
}

QList<QMap<QString, QString> > BCXMLManager::GetNodesWithKeyValue(QString /*key*/, QString /*value*/)
{
    QList<QMap<QString, QString> > models;

    return models;
}

QString BCXMLManager::GetAttribute(QString nodeName, QString key)
{
    QDomElement el = this->FindElementByNodeName(nodeName);
    return el.attribute(key);
}


QMap<QString, QString> BCXMLManager::GetAttributes(QString nodeName)
{
    QDomElement el = this->FindElementByNodeName(nodeName);
    QMap<QString,QString> map;
    for(int i = 0;i < el.attributes().count();i++)
    {
        QDomNode node = el.attributes().item(i);
         if(node.isAttr())
         {
            map.insert(node.toAttr().name(),node.toAttr().value());
         }

    }
    return map;
}

QList<QString> BCXMLManager::GetAttributesWithKeyInXML(QString fileName, QString key)
{
    QList<QString> atts;
    _fileName = fileName;
    this->CorrectedNode();;
    while (!_n.isNull())
    {
        if(_n.isElement())
        {
                QDomElement el = _n.toElement();

                if(!el.attribute(key).isEmpty())
                {

                   atts.append(el.attribute(key));
                }
        }

      _n = _n.nextSibling();
   }
    return atts;
}

QList<QMap<QString, QString> > BCXMLManager::DOM(QString fileName)
{
    QList<QMap<QString,QString> > models;
    if(fileName != _fileName)
    {
        QDomNode nil;
       _firstNode = nil;
    }
   _fileName = fileName;   
   this->CorrectedNode();
   while (!_n.isNull())
   {

       if(_n.isElement())
       {
           QDomElement el = _n.toElement();
           QMap<QString,QString> model;
           model = this->GetAttributes(el.tagName());
           model.insert("element",el.tagName());
           models.append(model);
       }

     _n = _n.nextSibling();

  }
   return models;
}

int BCXMLManager::GetNodeCount(QString fileName)
{
    _fileName = fileName;
    PrepareXML();
    return _n.parentNode().toElement().childNodes().count();
}
QDomNode BCXMLManager::PrepareXML()
{
    QFile file(_fileName);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << _fileName;
        qDebug("xml open error!");
        return QDomNode();
    }
    if(!_doc.setContent(&file)){

        file.close();
        return QDomNode();

    }
    file.close();
    QDomElement docElem = _doc.documentElement();
     _n = docElem.firstChild();
     _firstNode = _n;
     return _n;
}
//校正_n使其成为第一个Node
void BCXMLManager::CorrectedNode()
{
    if(_firstNode.isNull())
    {
        this->PrepareXML();
    }
    else
    {
        _n = _firstNode;
    }
}

QDomElement BCXMLManager::FindElementByNodeName(QString nodeName)
{
    this->CorrectedNode();
    while (!_n.isNull())
    {
        if(_n.isElement())
        {
                QDomElement el = _n.toElement();

                if(el.tagName() == nodeName)
                {
                     return el;
                }
        }

      _n = _n.nextSibling();
   }
  QDomElement nil;
  return nil;
}

bool BCXMLManager::Save()
{
    QFile file(_fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) return false;
    QTextStream out(&file);
    _doc.save(out,4);
    file.close();    
    QDomNode nil;
    _firstNode = nil;
    return true;
}

QString BCXMLManager::GetNode(int index)
{
    this->CorrectedNode();
   if(_doc.documentElement().childNodes().count() > 0)
   {
       if(index == -1) return _doc.documentElement().lastChild().nodeName();

       return _doc.documentElement().childNodes().at(index).nodeName();
   }
   return "NoFind";
}

void BCXMLManager::Common(QList<QMap<QString, QString> > */*models*/, QList<QString> */*atts*/,QString /*value*/)
{
//    QList<QMap<QString, QString> > m;
//    QMap<QString,QString> map;
//        this->CorrectedNode();;
//        while (!_n.isNull())
//        {
//            if(_n.isElement())
//            {
//                    QDomElement el = _n.toElement();

//                    if(!el.attribute(key).isEmpty())
//                    {
//                        if(models)
//                        {
//                            if(el.attribute(key) == value)
//                            {

//                               GetAttributes()
//                            }
//                        }

//                       atts.append(el.attribute(key));
//                    }
//            }

//          _n = _n.nextSibling();
//       }



}



