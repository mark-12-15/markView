#ifndef BCXMLMANAGER_H
#define BCXMLMANAGER_H
#include <QString>
#include <QMap>
#include <QDomNode>
#include <QDomDocument>
class BCXMLManager
{
public:
    BCXMLManager(QString fileName = "xxx.xml");
    /**
     * @brief CreateXMLFile   创建一个XML文件
     */
    bool CreateXMLFile(QString fileName);


    /**
     * @brief IsExistXmlFile 判断是否已经创建
     */
    bool IsExistXmlFile(QString fileName);


    /**
     * @brief containTheNode  判断XML文件中是否包含某个Node
     * @param nodeName
     * @return
     */
    bool ContainTheNode(QString nodeName);


    /**
      * @brief MoveNodeTo  移动某个Node、默认其他的Node向前挪一位或向后挪一位
      * @param to
      * @return
      */
     bool MoveNodeTo(QString nodeName, int to);


    /**
     * @brief CreateNode  创建一个结点
     */
     bool CreateNode(QString nodeName);


    /**
     * @brief AddAttribute 给指定的结点添加属性
     * @return
     */
    bool AddAttribute(QString nodeName,QMap<QString,QString> map);


    /**
     * @brief UpdateAttribute   更新某个Node的value值
     * @param nodeName
     * @param key
     * @param value
     * @return
     */
    bool UpdateAttribute(QString nodeName,QString key,QString value);


    /**
     * @brief UpdateAttributes   更新Node的Value值
     * @param nodeName
     * @param map
     * @return
     */
    bool UpdateAttributes(QString nodeName,QMap<QString,QString> map);


    /**
     * @brief deleateNode  删除Node
     * @param nodeName
     * @return
     */
    bool DeleateNode(QString nodeName);

    /**
     * @brief deleateNodeAt  根据索引删除Node
     * @param index
     * @return
     */
    bool DeleateNodeAt(int index);

    /**
     * @brief GetLastNode    获得最后一个节点名
     * @return
     */
    QString GetLastNode();

    /**
     * @brief GetNodeAt  根据索引获取NodeName
     * @param index
     * @return
     */
    QString GetNodeAt(int index);

    /**
     * @brief GetNodesWithKeyValue 查找XML文件中满足key(如：name)value是(如：BC)的Node
     * @param key    如：name
     * @param value  如：BC
     * @return
     */
    QList<QMap<QString,QString> > GetNodesWithKeyValue(QString key,QString value);

    /**
     * @brief GetAttribute  查找指定的节点key对应的Value值
     * @return
     */
    QString GetAttribute(QString nodeName,QString key);


    /**
     * @brief GetAttributes    获得某一个节点下的所有Attribute的key以及对应的value
     * @param nodeName
     * @return
     */
    QMap<QString,QString>  GetAttributes(QString nodeName);

    /**
     * @brief GetAttributesWithKeyInXML   查找XML文件中某一个key对应的所有value
     * @param fileName
     * @param key
     * @return
     */
    QList<QString> GetAttributesWithKeyInXML(QString fileName,QString key);

    /**
     * @brief DOM        解析XML文件
     * @param fileName
     * @return
     */
    QList<QMap<QString,QString> > DOM(QString fileName);

    /**                  查询XML中的节点数
     * @brief GetNodeCount
     * @param fileName
     * @return
     */
    int GetNodeCount(QString fileName);


//********************************************************《 私有 》************************************************************
private:
    /**
     * @brief CorrectedNode 校正_n成为第一个Node
     */
    void CorrectedNode();

    /**
     * @brief PrepareXML 打开XML文件
     * @return      返回第一个Node
     */
    QDomNode PrepareXML();

    /**
     * @brief FindElementByNodeName   根据NodeName返回当前的节点
     * @param nodeName
     * @return
     */
    QDomElement FindElementByNodeName(QString nodeName);

    /**
     * @brief Save    保存XML
     * @return
     */
    bool Save();

    QString GetNode(int index = -1);
    void Common(QList<QMap<QString, QString> > *models = NULL,QList<QString> *atts = NULL,QString value = "BC");  //
    QString _fileName;
    int _sort;
    QDomDocument _doc;
    QDomNode _n;
    QDomNode _firstNode;
};

#endif // BCXMLMANAGER_H
