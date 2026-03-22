pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Configure') {
            steps {
                bat '''
                if not exist build mkdir build
                cd build
                cmake ..
                '''
            }
        }

        stage('Build') {
            steps {
                bat '''
                cd build
                cmake --build . --config Release
                '''
            }
        }
    }

    post {
        success {
            archiveArtifacts artifacts: 'build/**/*.exe', fingerprint: true
        }
    }
}
