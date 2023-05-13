import UIKit

import AVFoundation

class ViewController: UIViewController {

    @IBOutlet weak var previewView: UIView!

    @IBOutlet weak var captureButton: UIButton!

    @IBOutlet weak var imageView: UIImageView!

    var captureSession: AVCaptureSession!

    var videoPreviewLayer: AVCaptureVideoPreviewLayer!

    var stillImageOutput: AVCaptureStillImageOutput!

    override func viewDidLoad() {

        super.viewDidLoad()

        // Create the AVCaptureSession

        captureSession = AVCaptureSession()

        // Add the video input

        let videoDevice = AVCaptureDevice.defaultDevice(withMediaType: AVMediaTypeVideo)

        let videoInput = AVCaptureDeviceInput(device: videoDevice, error: nil)

        if captureSession.canAddInput(videoInput) {

            captureSession.addInput(videoInput)

        }

        // Add the still image output

        stillImageOutput = AVCaptureStillImageOutput()

        stillImageOutput.outputSettings = [AVVideoCodecKey: AVVideoCodecJPEG]

        if captureSession.canAddOutput(stillImageOutput) {

            captureSession.addOutput(stillImageOutput)

        }

        // Configure the preview layer

        videoPreviewLayer = AVCaptureVideoPreviewLayer(session: captureSession)

        videoPreviewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill

        previewView.layer.addSublayer(videoPreviewLayer)

        // Start the capture session

        captureSession.startRunning()

    }

    @IBAction func captureButtonTapped(_ sender: Any) {

        // Create a AVCaptureStillImageRequest

        let stillImageRequest = AVCaptureStillImageRequest()

        stillImageRequest.stillImageSettings = [AVVideoCodecKey: AVVideoCodecJPEG]

        // Capture the still image

        stillImageOutput.captureStillImageAsynchronously(from: stillImageRequest, completionHandler: { (imageData, error) in

            if let imageData = imageData, let image = UIImage(data: imageData) {

                self.imageView.image = image

            }

        })

    }

}

