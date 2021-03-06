#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent)
{
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
  scale = 1.0f;
}

MyGLWidget::~MyGLWidget ()
{
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();
  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  glEnable(GL_DEPTH_TEST);
  up = glm::vec3(0,1,0);
    carregaShaders();
    createBuffers();
  viewTransform();
  modelTransform();
  projectTransform();

}

void MyGLWidget::paintGL ()
{
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  // Carreguem la transformació de model

  // Activem el VAO per a pintar la caseta
  glBindVertexArray (VAO_Homer);

  // pintemLS
  glDrawArrays(GL_TRIANGLES, 0, m.faces().size()*3);

  glBindVertexArray (0);
}

void MyGLWidget::resizeGL (int w, int h)
{
  glViewport(0, 0, w, h);
}

void MyGLWidget::keyPressEvent(QKeyEvent* event)
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_R: { // escalar a més gran
      rotar_esquerra();
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      rotar_dreta();
      break;
    }
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::createBuffers ()
{
    m.load("../../../models/HomerProves.obj");

    // Creació del Vertex Array Object per pintar
    glGenVertexArrays(1, &VAO_Homer);
    glBindVertexArray(VAO_Homer);

    glGenBuffers(1, &VBO_HomerPosicio);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerPosicio);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces().size() * 3 * 3, m.VBO_vertices(), GL_STATIC_DRAW);

    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    glGenBuffers(1, &VBO_HomerColor);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_HomerColor);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces().size() * 3 * 3, m.VBO_matdiff(), GL_STATIC_DRAW);


    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    glBindVertexArray (0);
}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/fragshad.frag");
  vs.compileSourceFile("shaders/vertshad.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  projLoc = glGetUniformLocation(program->programId(), "proj");
  viewLoc = glGetUniformLocation(program->programId(), "view");
}



void MyGLWidget::viewTransform () {
// glm::lookAt (OBS, VRP, UP)
    glm::mat4 View = glm::lookAt (glm::vec3(0,0,1),
                                  glm::vec3(0,0,0), up);
    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::modelTransform ()
{
    // Matriu de transformació de model
    glm::mat4 transform (1.0f);
    transform = glm::scale(transform, glm::vec3(scale));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::projectTransform() {
    //glm::perspective (FOV en radians, ra window, znear, zfar)
    glm::mat4 Proj = glm::perspective((float)M_PI/2.0f,1.0f,0.4f,3.0f);
    glUniformMatrix4fv(projLoc,1,GL_FALSE,&Proj[0][0]);
}




void MyGLWidget::rotar_esquerra() {
    if(up == glm::vec3(1,0,0)) up = glm::vec3(0,-1,0);
    else if(up == glm::vec3(0,-1,0)) up = glm::vec3(-1,0,0);
    else if(up == glm::vec3(-1,0,0)) up = glm::vec3(0,1,0);
    else up = glm::vec3(1,0,0);
    viewTransform();
}


void MyGLWidget::rotar_dreta() {
    if(up == glm::vec3(1,0,0)) up = glm::vec3(0,1,0);
    else if(up == glm::vec3(0,1,0)) up = glm::vec3(-1,0,0);
    else if(up == glm::vec3(-1,0,0)) up = glm::vec3(0,-1,0);
    else up = glm::vec3(1,0,0);
    viewTransform();
}
