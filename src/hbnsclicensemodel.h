/*
Copyright (c) 2015-2019, Hüssenbergnetz/Matthias Fehring
https://github.com/Huessenbergnetz/HBN_SFOS_Components
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of HBN_SFOS_Components nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef HBNSCLICENSEMODEL_H
#define HBNSCLICENSEMODEL_H

#include <QAbstractListModel>
#include <QUrl>
#include <vector>

namespace Hbnsc {

class LicenseModel : public QAbstractListModel
{
    Q_OBJECT
    Q_DISABLE_COPY(LicenseModel)
    struct Item;
    std::vector<Item> m_items;
public:
    explicit LicenseModel(QObject *parent = nullptr);
    ~LicenseModel() override;

    enum Roles {
        Name = Qt::UserRole + 1,
        Author,
        Version,
        Description,
        Website,
        License,
        LicenseFile,
        CustomLicenseFile,
        LicenseWebsite
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override final;
    QModelIndex index(int row, int column = 0, const QModelIndex &parent = QModelIndex()) const override final;
    QHash<int, QByteArray> roleNames() const override final;
    QVariant data(const QModelIndex &index, int role = Qt::UserRole) const override final;

protected:
    void add(const QString &name, const QString &author, const QString &version, const QUrl &website, const QString &description, const QString &license, const QString &licenseFile, const QUrl &licenseWebsite, const QUrl &customLicenseFile);
    void addSQLite();
    void addNemoNotifications();
    void addOpenSSL();
    void sortLicenses();
};

}

#endif // HBNSCLICENSEMODEL_H
